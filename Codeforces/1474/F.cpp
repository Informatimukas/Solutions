#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;
using ii = pair<int, int>;

constexpr int mod = 998244353;

struct matrix {
    vector<vector<int>> M;
    matrix(int n, int diag = 0) {
        M.resize(n, vector(n, 0));
        if (diag)
            for (int i = 0; i < n; i++)
                M[i][i] = diag;
    }
    matrix operator*(const matrix& oth) const {
        matrix res(M.size());
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M.size(); j++)
                for (int k = 0; k < M.size(); k++)
                    res.M[i][j] = (res.M[i][j] + static_cast<ll>(M[i][k]) * oth.M[k][j]) % mod;
        return res;
    }
    matrix operator^(ll k) const {
        matrix res(M.size(), 1);
        matrix A = *this;
        while (k) {
            if (k & 1)
                res = res * A;
            k >>= 1;
            A = A * A;
        }
        return res;
    }
};

int Solve(const vector<llll>& seq, int l, int r) {
    vector<ll> un;
    for (int i = l; i <= r; i++) {
        un.push_back(min(seq[i].first, seq[i].second));
        un.push_back(max(seq[i].first, seq[i].second) + 1);
    }
    ranges::sort(un);
    un.erase(ranges::unique(un).begin(), un.end());
    int s = r - l + 1;
    vector<int> res(s);
    for (int i = 0; i + 1 < un.size(); i++) {
        matrix A(s);
        for (int j = s - 1, k = r; j >= 0; j--, k--) {
            if (un[i] < min(seq[k].first, seq[k].second) ||
                un[i] > max(seq[k].first, seq[k].second)) {
                res[j] = 0;
                continue;
            }
            int nres = 0;
            for (int z = 0; z < j; z++) {
                A.M[j][z] = 1;
                nres = (nres + res[z]) % mod;
            }
            if (seq[k].first <= seq[k].second) {
                A.M[j][j] = 1;
                nres = (nres + res[j]) % mod;
            }
            if (i == 0)
                nres = (nres + 1) % mod;
            res[j] = nres;
        }
        A = A^(un[i + 1] - un[i] - 1);
        for (int j = s - 1; j >= 0; j--) {
            int nres = 0;
            for (int z = 0; z <= j; z++)
                nres = (nres + static_cast<ll>(A.M[j][z]) * res[z]) % mod;
            res[j] = nres;
        }
    }
    int tot = 0;
    for (auto& resi : res)
        tot = (tot + resi) % mod;
    return tot;
}

ll getLen(const ii& p, const vector<llll>& seq) {
    return seq[p.second].second - seq[p.first].second;
}

int Better(const ii& old, const ii& nw, const vector<llll>& seq) {
    ll len1 = getLen(old, seq);
    ll len2 = getLen(nw, seq);
    if (len1 != len2) return len1 < len2 ? 1: -1;
    if (old.first == nw.first)
        return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> d(n);
    ll cur = x;
    vector<llll> lr = {{x, x}};
    for (auto& di : d) {
        cin >> di;
        if (di == 0) continue;
        llll el = di > 0 ? llll{cur + 1, cur + di} : llll{cur - 1, cur + di};
        lr.push_back(el);
        cur += di;
    }
    int wh = 0;
    vector<ii> seq;
    for (int i = 0; i < lr.size(); i++) {
        if (lr[i].second < lr[wh].second)
            wh = i;
        ii nw = {wh, i};
        while (true) {
            if (seq.empty()) {
                seq.push_back(nw);
                break;
            }
            int b = Better(seq.back(), nw, lr);
            if (b == 1) seq.pop_back();
            else if (b == -1) break;
            else {
                seq.push_back(nw);
                break;
            }
        }
    }
    ll best = getLen(seq.back(), lr);
    cout << best + 1 << " ";
    if (best == 0) {
        cout << abs(cur - x) + 1 << "\n";
        return 0;
    }
    int res = 0;
    for (auto& p : seq)
        res = (res + Solve(lr, p.first, p.second)) % mod;
    cout << res << "\n";
    return 0;
}