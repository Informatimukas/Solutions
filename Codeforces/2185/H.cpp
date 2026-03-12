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
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }

        for (auto& x : a)
            cin >> x;

    }
    return 0;
}
