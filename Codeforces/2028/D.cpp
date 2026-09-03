#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxd = 3;
const string names = "qkj";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<array<int, 3>> my(n + 1);
        array<ii, 3> best;
        for (int z = 0; z < Maxd; z++)
            for (int i = 1; i <= n; i++)
                cin >> my[i][z];
        vector<ii> par(n + 1);
        vector tk(n + 1, false);
        tk[1] = true;
        for (int z = 0; z < Maxd; z++)
            best[z] = {my[1][z], 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < Maxd; j++)
                if (my[i][j] < best[j].first) {
                    par[i] = {best[j].second, j};
                    tk[i] = true;
                    break;
                }
            if (tk[i])
                for (int j = 0; j < Maxd; j++)
                    best[j] = max(best[j], {my[i][j], i});
        }
        if (!tk[n]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<ii> res;
        int v = n;
        while (v != 1) {
            res.emplace_back(par[v].second, v);
            v = par[v].first;
        }
        cout << res.size() << "\n";
        for (int i = res.size() - 1; i >= 0; i--)
            cout << names[res[i].first] << " " << res[i].second << "\n";
    }
    return 0;
}
