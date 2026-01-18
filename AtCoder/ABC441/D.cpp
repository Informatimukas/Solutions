#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Traverse(int v, const vector<vector<ii>>& neigh, vector<bool>& taken, int l, int s, int t) {
    if (l == 0) {
        if (s <= 0 && 0 <= t)
            taken[v] = true;
        return;
    }
    for (auto& [u, cost] : neigh[v])
        Traverse(u, neigh, taken, l - 1, s - cost, t - cost);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector neigh(n + 1, vector<ii>());
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        neigh[x].emplace_back(y, c);
    }
    vector taken(n + 1, false);
    Traverse(1, neigh, taken, l, s, t);
    bool pr = false;
    for (int i = 1; i <= n; i++)
        if (taken[i]) {
            if (pr)
                cout << " ";
            else pr = true;
            cout << i;
        }
    cout << "\n";
    return 0;
}
