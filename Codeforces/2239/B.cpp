#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Get(const vector<ll>& sum, int ind) {
    if (ind < 0) {
        ind += sum.size();
        return sum[ind] - sum.back();
    }
    if (ind >= sum.size()) {
        ind -= sum.size();
        return sum[ind] + sum.back();
    }
    return sum[ind];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        vector<ll> sum(n);
        for (int i = 0; i < n; i++) {
            sum[i] = a[i];
            if (i > 0)
                sum[i] += sum[i - 1];
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
            res += max(0ll, (2 * d + 1) * a[i] - (Get(sum, i + d) - Get(sum, i - d - 1)));
        cout << res << "\n";
    }
    return 0;
}
