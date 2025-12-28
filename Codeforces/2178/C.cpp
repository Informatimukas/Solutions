#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector bestSum(n + 1, 0ll);
        vector sum(n + 1, 0ll);
        ll res = -Inf;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ll val = a[i];
            if (i == n - 1)
                val = -val;
            else if (i)
                val = abs(val);
            bestSum[i] = val;
            sum[i] = a[i];
            if (i) {
                bestSum[i] += bestSum[i - 1];
                sum[i] += sum[i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            ll cand = 0;
            if (i)
                cand += bestSum[i - 1];
            if (i + 1 < n)
                cand -= (sum[n - 1] - sum[i]);
            res = max(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
