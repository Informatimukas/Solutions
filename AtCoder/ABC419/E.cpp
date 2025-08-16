#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> A(n);
    for (auto& x : A)
        cin >> x;
    vector dp(l + 1, vector(m, Inf));
    dp[0][0] = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int k = i; k < n; k += l) {
                int add = j - A[k] % m;
                if (add < 0) add += m;
                cur += add;
            }
            for (int k = 0; k < m; k++) {
                int nk = (k + j) % m;
                dp[i + 1][nk] = min(dp[i + 1][nk], dp[i][k] + cur);
            }
        }
    cout << dp[l][0] << "\n";
    return 0;
}