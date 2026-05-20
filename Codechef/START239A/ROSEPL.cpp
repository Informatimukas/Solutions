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
        ll m, k;
        cin >> n >> m >> k;
        vector<ll> seq;
        ll full = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            full += a / k;
            if (a % k)
                seq.push_back(a % k);
        }
        m++;
        ll tk = min(full, m / (k + 1));
        ll res = tk * k;
        m -= tk * (k + 1);
        full -= tk;
        if (full > 0) {
            res += max(0ll, m - 1);
            cout << res << "\n";
            continue;
        }
        ranges::sort(seq, greater());
        for (auto x : seq)
            if (x + 1 <= m) {
                m -= (x + 1);
                res += x;
            } else {
                res += max(0ll, m - 1);
                break;
            }
        cout << res << "\n";
    }
    return 0;
}
