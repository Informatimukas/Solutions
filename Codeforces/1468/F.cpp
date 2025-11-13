#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

ii Get(const ii& a, const ii& b) {
    ii res = {b.first - a.first, b.second - a.second};
    int g = __gcd(abs(a.first - b.first), abs(a.second - b.second));
    return {res.first / g, res.second / g};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<ii, int> M;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            ii w = Get({x, y}, {u, v});
            res += M[{-w.first, -w.second}];
            M[w]++;
        }
        cout << res << "\n";
    }
    return 0;
}
