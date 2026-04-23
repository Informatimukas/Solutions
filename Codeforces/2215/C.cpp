#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Traverse(int v, int c, vector<int>& col, const vector<vector<ii>>& neigh) {
    if (col[v] != -1)
        return;
    col[v] = c;
    for (auto [u, dif] : neigh[v]) {
        int ncol = dif ? 1 - c : c;
        Traverse(u, ncol, col, neigh);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, q;
    cin >> T >> q;
    if (q == 1)
        while (T--) {
            int n, s;
            cin >> n >> s;
            s--;
            for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                if (static_cast<bool>(s & 1 << (u - 1)) != static_cast<bool>(s & 1 << (v - 1)))
                    swap(u, v);
                cout << u << " " << v << endl;
            }
        }
    else while (T--) {
        int n;
        cin >> n;
        vector col(n + 1, -1);
        vector<vector<ii>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            int dif = a > b;
            neigh[a].emplace_back(b, dif);
            neigh[b].emplace_back(a, dif);
        }
        Traverse(n, 0, col, neigh);
        int s = 0;
        for (int i = 0; i < n - 1; i++)
            s |= col[i + 1] << i;
        s++;
        cout << s << endl;
    }
    return 0;
}
