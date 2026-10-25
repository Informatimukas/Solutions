#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        array mx = {-Inf, -Inf};
        array mn = {Inf, Inf};
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            mx[x % 2] = max(mx[x % 2], x);
            mn[x % 2] = min(mn[x % 2], x);
        }
        array cur = {-Inf, -Inf};
        bool ok = true;
        for (auto x : a)
            if (x >= cur[x % 2])
                cur[x % 2] = x;
            else {
                int oth = 1 - x % 2;
                if (mx[oth] <= cur[x % 2] && mn[oth] >= x)
                    ok = false;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
