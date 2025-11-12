#include <bits/stdc++.h>
using namespace std;

constexpr int Maxm = 5;
constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector dp(n + 1, vector(Maxm, Inf));
        for (int j = 0; j < Maxm; j++)
            dp[1][j] = j;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < Maxm; j++)
                for (int k = 0; k < Maxm; k++)
                    if (a[i - 1] + j != a[i] + k)
                        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + k);
        cout << *ranges::min_element(dp[n]) << "\n";
    }
    return 0;
}