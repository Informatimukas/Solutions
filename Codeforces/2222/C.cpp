#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

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
        for (auto& x : a)
            cin >> x;
        auto seq = a;
        ranges::sort(seq);
        int med = seq[seq.size() / 2];
        vector dp(n + 1, -Inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int les = 0, eq = 0, mor = 0;
            for (int j = i; j < n; j++) {
                if (a[j] < med)
                    les++;
                else if (a[j] == med)
                    eq++;
                else mor++;
                if ((j - i) % 2 == 0 && les + eq > mor && mor + eq > les)
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
