#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector C(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    vector step(n + 1, vector(n, 0ll));
    step[n][0] = 1;
    for (int i = 1; i <= n; i++) {
        auto nstep = step;
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < n; k++)
                if (step[j][k])
                    for (int t = 1; t <= j; t++) {
                        int nk = max(k, t - 1);
                        nstep[j - t][nk] = (nstep[j - t][nk] + step[j][k] * C[j][t]) % mod;
                    }
        step = std::move(nstep);
    }
    vector<ll> add(n);
    for (int j = 0; j < n; j++)
        add[j] = step[0][j];
    vector good(n, 0ll);
    good[0] = 1;
    for (int i = 0; i < n * n; i++)
        for (int j = n - 1; j >= 0; j--) {
            auto ways = good[j];
            good[j] = 0;
            for (int k = 0; j + k < n; k++)
                good[j + k] = (good[j + k] + ways * add[k]) % mod;
        }
    ll sum = 0;
    for (auto& x : good)
        sum = (sum + x) % mod;
    cout << sum << "\n";
    return 0;
}
