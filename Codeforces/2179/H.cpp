#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;
using ii = pair<int, int>;

constexpr int Maxk = 18;

llll Add(const llll& a, const llll& b) {
    return {a.first + b.first, a.second + b.second};
}

void Update(vector<vector<llll>>& M, int n, const array<int, 3>& upd) {
    for (int i = 0; upd[0] + (1 << i) <= n; i++) {
        int key = upd[0] % (1 << i);
        ll mult = i == 0 ? 1 : 1 << (i - 1);
        llll add = {mult * upd[2], -upd[0] * mult * upd[2]};
        M[i][key] = Add(M[i][key], add);
    }
}

ll getVal(const vector<vector<llll>>& M, int ind) {
    llll cur;
    for (int i = 0; 1 << i <= ind; i++) {
        cur = Add(cur, M[i][ind % (1 << i)]);
    }
    return cur.first * ind + cur.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<llll>> M(Maxk);
    for (int i = 0; i < Maxk; i++)
        M[i].resize(1 << i);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<vector<array<int, 3>>> quer(n + 2);
        while (q--) {
            int l, r;
            cin >> l >> r;
            quer[l].push_back({l - 1, r, 1});
            quer[r + 1].push_back({l - 1, r, -1});
        }
        for (int i = 1; i <= n; i++) {
            for (auto& x : quer[i])
                Update(M, n, x);
            cout << getVal(M, i) << (i + 1 <= n ? ' ' : '\n');
        }
        for (auto& x : quer[n + 1])
            Update(M, n, x);
    }
    return 0;
}
