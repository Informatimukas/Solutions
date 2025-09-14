#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), sum(n + 1), sum1(n + 1), sum2(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum1[i] = sum1[i - 1] + i * a[i];
        sum2[i] = sum2[i - 1] + i * i * a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll s = sum[r] - sum[l - 1];
        ll s1 = sum1[r] - sum1[l - 1];
        ll s2 = sum2[r] - sum2[l - 1];
        int R = r + 1;
        int L = l - 1;
        ll res = R * s1 - s * R * L - s2 + L * s1;
        cout << res << "\n";
    }
    return 0;
}
