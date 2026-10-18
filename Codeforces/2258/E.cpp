#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200050;

struct pos {
    vector<int> seq;
    vector<int> BIT;
};

int Query(const pos& p, int rig) {
    auto ind = distance(p.seq.begin(), ranges::upper_bound(p.seq, rig));
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += p.BIT[i];
    return res;
}

void Update(pos& p, int rig) {
    auto ind = distance(p.seq.begin(), ranges::lower_bound(p.seq, rig));
    for (int i = ind + 1; i < p.BIT.size(); i += i & -i)
        p.BIT[i]++;
}

void Attach(vector<pos>& st, int v, int l, int r, int a, int b, int rig) {
    if (l == a && r == b) {
        if (st[v].seq.empty() || st[v].seq.back() < rig)
            st[v].seq.push_back(rig);
        return;
    }
    int m = (l + r) / 2;
    if (a <= m)
        Attach(st, 2 * v, l, m, a, min(m, b), rig);
    if (m + 1 <= b)
        Attach(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, rig);
}

void Initialize(vector<pos>& st, int v, int l, int r) {
    st[v].BIT.resize(st[v].seq.size() + 1);
    if (l >= r)
        return;
    int m = (l + r) / 2;
    Initialize(st, 2 * v, l, m);
    Initialize(st, 2 * v + 1, m + 1, r);
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, int rig) {
    if (l == a && r == b) {
        Update(st[v], rig);
        return;
    }
    int m = (l + r) / 2;
    if (a <= m)
        Update(st, 2 * v, l, m, a, min(m, b), rig);
    if (m + 1 <= b)
        Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, rig);
}

int Query(const vector<pos>& st, int v, int l, int r, int x, int rig) {
    int res = Query(st[v], rig);
    if (l >= r)
        return res;
    int m = (l + r) / 2;
    if (x <= m)
        res += Query(st, 2 * v, l, m, x, rig);
    else res += Query(st, 2 * v + 1, m + 1, r, x, rig);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector prime(Maxn, true);
    vector<int> seq;
    for (int i = 2; i < Maxn; i++)
        if (prime[i]) {
            int j = 1;
            while (j <= Maxn / i) {
                j *= i;
                seq.push_back(j);
            }
            for (int z = i + i; z < Maxn; z += i)
                prime[z] = false;
        }
    ranges::sort(seq);
    vector<vector<int>> divs(Maxn);
    for (auto x : seq)
        for (int j = x; j < Maxn; j += x)
            divs[j].push_back(x);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int lim = *ranges::upper_bound(seq, n);
        vector<pos> st(4 * (n + 1));
        vector<int> a(n + 1);
        vector<vector<int>> my(lim + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (auto x : divs[a[i]]) {
                int lst = my[x].empty() ? 0 : my[x].back();
                Attach(st, 1, 1, n, lst + 1, i, i);
                my[x].push_back(i);
            }
        }
        Initialize(st, 1, 1, n);
        vector<int> res;
        for (int i = 0; i < seq.size() && seq[i] <= lim; i++) {
            bool ok = false;
            int lst = 0;
            for (auto ind : my[seq[i]]) {
                if (lst + 1 < ind && Query(st, 1, 1, n, lst + 1, ind - 1) >= i)
                    ok = true;
                Update(st, 1, 1, n, lst + 1, ind, ind);
                lst = ind;
            }
            if (lst + 1 <= n && Query(st, 1, 1, n, lst + 1, n) >= i)
                ok = true;
            if (ok)
                res.push_back(seq[i]);
        }
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
