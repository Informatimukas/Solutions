#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll k, x;
        cin >> k >> x;
        ll a = x;
        ll b = (1ll << k + 1ll) - x;
        vector<int> res;
        while (a != b)
            if (a < b) {
                res.push_back(1);
                b -= a;
                a += a;
            } else {
                res.push_back(2);
                a -= b;
                b += b;
            }
        cout << res.size() << "\n";
        if (res.empty()) cout << "\n";
        else for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << (i - 1 >= 0? ' ': '\n');
    }
    return 0;
}