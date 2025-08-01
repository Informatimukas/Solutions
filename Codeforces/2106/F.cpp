#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Sum(ll a) { return (a + 1) * a / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> lef(n), rig(n);
        ll res = -1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            lef[i] = cur;
            if (s[i] == '0') cur++;
            else cur = 0;
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            rig[i] = cur;
            if (s[i] == '0') cur++;
            else cur = 0;
        }
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                res = max(res, static_cast<ll>(i) * rig[i] + Sum(rig[i]) +
                    static_cast<ll>(n - 1 - i) * lef[i] + Sum(lef[i]) + 1);
        if (res == -1)
            res = Sum(n - 1);
        cout << res << '\n';
    }
    return 0;
}
