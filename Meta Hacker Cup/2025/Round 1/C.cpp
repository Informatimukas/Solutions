#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += static_cast<ll>(i) * (n + 1 - i);
        map<int, int> M;
        int cur = 0;
        M[cur]++;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            cur ^= a;
            M[cur]++;
        }
        for (auto& c : M | views::values)
            for (int i = 2; i <= c; i++)
                res -= static_cast<ll>(i - 1) * (c + 1 - i);
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}