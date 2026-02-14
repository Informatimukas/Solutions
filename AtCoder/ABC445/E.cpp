#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 10000005;
constexpr ll mod = 998244353;

struct pos {
    array<int, 2> best;
    int col{0};
};

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1ll)
            res = res * a % mod;
        p >>= 1ll;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll a) { return toPower(a, mod - 2); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector mx(Maxm, 0);
    for (int i = 2; i < Maxm; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxm; j += i)
                mx[j] = i;
    vector<pos> st(Maxm);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        ll all = 1;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            int num = x;
            while (num > 1) {
                int p = mx[num], c = 0;
                while (mx[num] == p) {
                    num /= p;
                    ++c;
                }
                if (st[p].col != tc) {
                    st[p].col = tc;
                    st[p].best = {0, 0};
                }
                if (c > st[p].best[0]) {
                    all = all * toPower(p, c - st[p].best[0]) % mod;
                    st[p].best[1] = st[p].best[0];
                    st[p].best[0] = c;
                } else if (c > st[p].best[1])
                    st[p].best[1] = c;
            }
        }
        for (int i = 0; i < a.size(); i++) {
            int num = a[i];
            ll cur = all;
            while (num > 1) {
                int p = mx[num], c = 0;
                while (mx[num] == p) {
                    num /= p;
                    ++c;
                }
                if (st[p].best[0] == c)
                    cur = cur * Inv(toPower(p, st[p].best[0] - st[p].best[1])) % mod;
            }
            cout << cur << (i + 1 < a.size() ? ' ' : '\n');
        }
    }
    return 0;
}
