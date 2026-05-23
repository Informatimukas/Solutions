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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll mx = 0;
        int wth;
        ll cur = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] > 0) {
                if (cur - 2 * a[i] > mx) {
                    mx = cur - 2 * a[i];
                    wth = i;
                }
            } else cur += 2 * abs(a[i]);
        vector<int> res;
        if (mx > 0) {
            bool inv = false;
            for (int i = wth - 1; i > 0; i--) {
                if (inv)
                    a[i] = -a[i];
                if (a[i] > 0) {
                    inv ^= true;
                    res.push_back(i);
                }
            }
            res.push_back(wth);
        }
        cout << res.size() << "\n";
        if (res.empty()) {
            cout << "\n";
            continue;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
