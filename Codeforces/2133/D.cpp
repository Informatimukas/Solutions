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
        vector<int> h(n);
        for (auto& x : h)
            cin >> x;
        vector best(n, numeric_limits<ll>::max());
        best[n - 1] = 0;
        for (int i = n - 1; i > 0; i--) {
            best[i - 1] = min(best[i - 1], best[i] + h[i] - 1);
            if (i > 1) {
                ll cand = h[i - 1] + max(0, h[i] - i) + best[i];
                best[i - 2] = min(best[i - 2], cand);
            }
        }
        ll res = best[0] + h[0];
        cout << res << "\n";
    }
    return 0;
}
