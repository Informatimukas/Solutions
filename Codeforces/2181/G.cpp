#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llb = pair<ll, bool>;

constexpr int Inf = 1000000007;

llb Solve(const vector<ll>& a, vector<ll>& b, ll x) {
    array mx = {0ll, 0ll};
    mx[0] = b[0] = x;
    for (int i = 1; i < a.size(); i++) {
        b[i] = a[i] - b[i - 1];
        if (b[i] < 0)
            return i % 2 ? llb{Inf, false} : llb{Inf, true};
        if (b[i] > a[i])
            return i % 2 ? llb{Inf, true} : llb{Inf, false};
        mx[i % 2] = max(mx[i % 2], b[i]);
    }
    ll carryb = a[0] - b.back();
    if (carryb != x)
        return carryb > x ? llb{Inf, true} : llb{Inf, false};
    if (mx[0] >= mx[1])
        return {mx[0], false};
    return {mx[1], true};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll sum = 0;
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }
        ll lef = 0, rig = a[0];
        ll best = Inf;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            auto [mx, rec] = Solve(a, b, mid);
            if (mx < best)
                best = mx;
            if (rec)
                lef = mid + 1;
            else rig = mid - 1;
        }
        ll res = max(best, (sum / 2 + n - 2) / (n - 1));
        cout << res << "\n";
    }
    return 0;
}
