#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;
constexpr int inv2 = (mod + 1) / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> L, R;
        for (auto& x : a) {
            cin >> x;
            if (L.empty() || L.back() < x)
                L.push_back(x);
        }
        for (int i = n - 1; i >= 0; i--)
            if (R.empty() || R.back() < a[i])
                R.push_back(a[i]);
        ranges::reverse(L);
        ranges::reverse(R);
        int mx = L[0];
        vector dpR(n + 1, vector(R.size() + 1, 0));
        dpR[n][R.size()] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dpR[i][R.size()] = 1;
            for (int j = R.size() - 1; j >= 0; j--) {
                dpR[i][j] = dpR[i + 1][j];
                if (a[i] > R[j]) continue;
                dpR[i][j] = (dpR[i][j] + dpR[i + 1][j]) % mod;
                if (a[i] == R[j])
                    dpR[i][j] = (dpR[i][j] + dpR[i + 1][j + 1]) % mod;
            }
        }
        vector dpL(n + 1, vector(L.size() + 1, 0));
        dpL[0][L.size()] = 1;
        for (int i = 0; i < n; i++) {
            dpL[i + 1][L.size()] = 1;
            for (int j = L.size() - 1; j >= 0; j--) {
                dpL[i + 1][j] = dpL[i][j];
                if (a[i] > L[j]) continue;
                dpL[i + 1][j] = (dpL[i + 1][j] + dpL[i][j]) % mod;
                if (a[i] == L[j])
                    dpL[i + 1][j] = (dpL[i + 1][j] + dpL[i][j + 1]) % mod;
            }
        }
        vector<int> pw2(n + 1), ipw2(n + 1);
        pw2[0] = ipw2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw2[i] = 2ll * pw2[i - 1] % mod;
            ipw2[i] = static_cast<ll>(inv2) * ipw2[i - 1] % mod;
        }
        int res = 0, lef = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == mx) {
                res = (res + static_cast<ll>(dpL[i][1]) * dpR[i + 1][1]) % mod;
                res = (res + static_cast<ll>(lef) * dpR[i + 1][1] % mod * pw2[i]) % mod;
                lef = (lef + static_cast<ll>(dpL[i][1]) * ipw2[i + 1]) % mod;
            }
        cout << res << "\n";
    }
    return 0;
}
