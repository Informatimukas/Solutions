#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

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
        vector<lli> sum(n);
        ll cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += a[i];
            sum[i] = {cur, i};
        }
        ranges::sort(sum);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[sum[i].second] = i + 1;
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
