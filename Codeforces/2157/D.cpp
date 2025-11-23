#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll takeFirst(const vector<ll>& sum, int cnt) {
    if (cnt == 0)
        return 0;
    return sum[cnt - 1];
}

ll takeLast(const vector<ll>& sum, int cnt) {
    ll res = sum.back();
    if (cnt < sum.size())
        res -= sum[sum.size() - 1 - cnt];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        vector<ll> sum(n);
        for (int i = 0; i < n; i++) {
            sum[i] = a[i];
            if (i)
                sum[i] += sum[i - 1];
        }
        ll res = 0;
        for (int i = 0; i <= n; i++) {
            int tk1 = i + (n - i) / 2;
            int tk2 = (n - i) / 2;
            res = max(res, static_cast<ll>(i) * l + takeLast(sum, tk2) - takeFirst(sum, tk1));
            res = max(res, -static_cast<ll>(i) * r + takeLast(sum, tk1) - takeFirst(sum, tk2));
        }
        cout << res << "\n";
    }
    return 0;
}