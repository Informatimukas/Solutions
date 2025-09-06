#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 20;
constexpr int Maxk = 10;
constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector dp(1 << Maxb, 1);
    for (int z = 0; z < n; z++) {
        int a;
        cin >> a;
        int lst = a & ((1 << Maxk) - 1);
        for (int i = 0; i < 1 << Maxk; i++)
            if ((lst | i) == i)
                dp[a | i] = static_cast<ll>(dp[a | i]) * a % mod;
        int res = 1;
        int fir = a >> Maxk;
        for (int i = 0; i < 1 << Maxk; i++)
            if ((i | fir) == fir)
                res = static_cast<ll>(res) * dp[(i << Maxk) | lst] % mod;
        cout << res << "\n";
    }
    return 0;
}
