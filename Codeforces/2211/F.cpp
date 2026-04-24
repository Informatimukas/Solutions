#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 676767677;

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

ll Solve(int l, int r, int n, int dep, const vector<ll>& ways) {
    if (l > r)
        return 0;
    int mid = (l + r) / 2;
    ll res = ways[n];
    if (l > 0)
        res = (res - ways[n - (mid - l + 1)] + mod) % mod;
    if (r < n - 1)
        res = (res - ways[n - (r - mid + 1)] + mod) % mod;
    if (l > 0 && r < n - 1)
        res = (res + ways[n - (r - l + 2)] + mod) % mod;
    return (dep * res + Solve(l, mid - 1, n, dep + 1, ways) +
        Solve(mid + 1, r, n, dep + 1, ways)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ll> ways(n + 1);
        ways[0] = 1;
        for (int i = 1; i <= n; i++)
            ways[i] = ways[i - 1] * (m + i - 1) % mod * Inv(i) % mod;
        cout << Solve(0, n - 1, n, 1, ways) << "\n";
    }
    return 0;
}
