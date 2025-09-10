#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        ll mx = 0;
        for (int i = 1; i <= n; i++) {
            int lef = 1, rig = min(i - 1, n - i);
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (a[mid] + a[i + mid] < 2 * a[i])
                    lef = mid + 1;
                else rig = mid - 1;
            }
            mx = max(mx, 2ll * rig * a[i] - (sum[rig] + sum[i + rig] - sum[i]));
        }
        cout << mx + sum[n] << "\n";
    }
    return 0;
}
