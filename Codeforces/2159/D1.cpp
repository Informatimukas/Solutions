#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        vector<ll> seq;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            while (!seq.empty() && a <= seq.back())
                seq.pop_back();
            seq.push_back(a);
        }
        vector<ll> dp(seq.size() + 1, Inf);
        dp[0] = 0;
        for (int i = 0; i < seq.size(); i++) {
            ll cur = 0;
            ll pnt = i;
            while (pnt < seq.size()) {
                cur = max(cur + 1, (seq[pnt] + seq[i] - 1) / seq[i]);
                pnt = distance(seq.begin(), ranges::upper_bound(seq, cur * seq[i]));
                if (cur > pnt - i)
                    pnt = i + cur;
                else dp[pnt] = min(dp[pnt], dp[i] + cur);
            }
        }
        cout << dp[seq.size()] << "\n";
    }
    return 0;
}
