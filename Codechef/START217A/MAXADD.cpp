#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Sum(ll lef, ll rig) { return (lef + rig) * (rig - lef + 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for (auto& x : A)
            cin >> x;
        vector<int> B(n);
        for (auto& x : B)
            cin >> x;
        ll mx = 0, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, A[i] + sum);
            sum += B[i];
        }
        ll res = 0;
        if (sum > mx)
            res = static_cast<ll>(m) * sum + Sum(1, m);
        else {
            ll tk = min(mx - sum, static_cast<ll>(m));
            res += mx * tk;
            ll lef = tk + 1;
            if (lef <= m)
                res += (m - lef + 1) * sum + Sum(lef, m);
        }
        cout << res << "\n";
    }
    return 0;
}
