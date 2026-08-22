#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;
constexpr int Maxk = 10;
constexpr int Maxm = 20;
constexpr int Maxn = 200005;

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

int Normalize(int a, const vector<int>& mx) {
    int res = 1;
    while (a > 1) {
        int cur = mx[a];
        res *= cur;
        while (mx[a] == cur)
            a /= cur;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxn);
    vector<int> pcnt(Maxn);
    for (int i = 2; i < Maxn; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxn; j += i) {
                mx[j] = i;
                pcnt[j]++;
            }
    vector<bool> norm(Maxn);
    for (int i = 1; i < Maxn; i++)
        norm[i] = Normalize(i, mx) == i;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[Normalize(a, mx)]++;
        }
        vector<ll> global(Maxm);
        vector total(n + 1, vector<ll>(Maxm));
        for (int i = n; i >= 1; i--)
            if (norm[i]) {
                int my = pcnt[i];
                vector<ll> has(Maxk);
                for (int j = i; j <= n; j += i)
                    if (norm[j]) {
                        int sam = pcnt[j / i];
                        for (int z = 0; z + sam < Maxm; z++)
                            total[i][z + sam] -= total[j][z];
                        total[i][my + 2 * sam] += cnt[j] * (cnt[j] - 1) / 2;
                        for (int z = 0; z < Maxk; z++)
                            total[i][my + z + sam] += has[z] * cnt[j];
                        has[sam] += cnt[j];
                    }
                for (int z = 0; z < Maxm; z++)
                    global[z] += total[i][z];
            }
        ll res = 0;
        for (int i = 1; i < Maxm; i++)
            res = (res + global[i] % mod * toPower(i, k)) % mod;
        cout << res << "\n";
    }
    return 0;
}
