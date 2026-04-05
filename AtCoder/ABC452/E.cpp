#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;
constexpr int Maxn = 1000005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector a(Maxn, 0ll), mult(Maxn, 0ll);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < Maxn; i++) {
        mult[i] = a[i] * i % mod;
        a[i] = (a[i] + a[i - 1]) % mod;
        mult[i] = (mult[i] + mult[i - 1]) % mod;
    }
    ll res = 0;
    for (int j = 1; j <= m; j++) {
        ll b;
        cin >> b;
        for (int i = j; i < Maxn; i += j) {
            ll sum = a[i - 1];
            if (i > j)
                sum = (sum - a[i - j - 1] + mod) % mod;
            ll my = mult[i - 1];
            if (i > j)
                my = (my - mult[i - j - 1] + mod) % mod;
            ll block = (my - (i - j) * sum % mod + mod) % mod;
            res = (res + block * b) % mod;
        }
    }
    cout << res << "\n";
    return 0;
}
