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
        int mxodd = 0;
        vector<int> even;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2)
                mxodd = max(mxodd, a);
            else even.push_back(a);
        }
        if (mxodd == 0) {
            for (int i = 0; i < n; i++)
                cout << "0" << (i + 1 < n ? ' ' : '\n');
            continue;
        }
        ranges::sort(even, greater());
        vector sum(even.size() + 1, 0ll);
        for (int i = 0; i < even.size(); i++)
            sum[i + 1] = sum[i] + even[i];
        for (int i = 1; i <= n; i++) {
            ll res;
            if (i <= even.size() + 1)
                res = sum[i - 1] + mxodd;
            else if (even.size() % 2 != i % 2)
                res = sum[even.size()] + mxodd;
            else if (even.empty() || i == n)
                res = 0;
            else res = sum[even.size() - 1] + mxodd;
            cout << res << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
