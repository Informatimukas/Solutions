#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        if (a.size() % 2 == 0)
            a.push_back(0);
        ll res = 0;
        for (int i = 0; i + 2 < a.size(); i += 2) {
            int w = a[i] + a[i + 2] - a[i + 1];
            if (w >= 0) {
                res += w;
                a[i + 2] -= min(a[i + 2], w);
            }
        }
        cout << res << "\n";
    }
    return 0;
}