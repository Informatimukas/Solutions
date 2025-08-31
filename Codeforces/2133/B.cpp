#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> g(n);
        for (auto& x : g)
            cin >> x;
        ranges::sort(g);
        long long res = 0;
        for (int i = 1; i <= g.size(); i += 2)
            res += g[g.size() - i];
        cout << res << "\n";
    }
    return 0;
}
