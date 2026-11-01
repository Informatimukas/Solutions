#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(int ind, int k, int x, const vector<int>& a, const vector<ll>& sum) {
    int lef = x <= ind / k ? k * x : ind;
    return (x + lef) * static_cast<ll>(a[ind]) - (lef ? sum[lef - 1] : 0) - (sum[ind + x] - sum[ind]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<ll> sum(n);
        ll S = 0;
        for (auto& x : a) {
            cin >> x;
            S += x;
        }
        ranges::sort(a);
        for (int i = 0; i < n; i++) {
            sum[i] = a[i];
            if (i)
                sum[i] += sum[i - 1];
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int lef = 0, rig = min(i, n - 1 - i);
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                ll got = Solve(i, k, mid, a, sum);
                res = max(res, got);
                if (mid < rig && Solve(i, k, mid + 1, a, sum) > got)
                    lef = mid + 1;
                else rig = mid - 1;
            }
        }
        res += S;
        cout << res << "\n";
    }
    return 0;
}
