#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ii> E(m);
    for (auto& [a, b] : E) {
        cin >> a >> b;
        a--;
        b--;
    }
    int res = m;
    for (int i = 0; i < 1 << n; i++) {
        int cand = 0;
        for (auto& [a, b] : E) {
            bool acol = i & 1 << a;
            bool bcol = i & 1 << b;
            cand += acol == bcol;
        }
        res = min(res, cand);
    }
    cout << res << "\n";
    return 0;
}
