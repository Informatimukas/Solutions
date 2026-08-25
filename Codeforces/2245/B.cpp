#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 4000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a, greater());
        ll res = -Inf;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i] - c;
            if ((i + 1) * 2 >= n)
                res = max(res, cur);
        }
        cout << res << "\n";
    }
    return 0;
}
