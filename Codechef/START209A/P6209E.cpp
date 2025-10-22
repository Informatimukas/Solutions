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
        int n, m;
        cin >> n >> m;
        map<int, int> M;
        ll res = 0;
        for (int t = 0; t < 2; t++)
            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                res += a;
                M[a]++;
            }
        for (auto& [key, value] : M)
            if (value > n)
                res -= 2 * static_cast<ll>(key) * (value - n);
        cout << res << "\n";
    }
    return 0;
}
