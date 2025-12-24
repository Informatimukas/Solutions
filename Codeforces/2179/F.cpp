#include <bits/stdc++.h>
using namespace std;

const string rgb = "rgb";
constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string player;
    cin >> player;
    if (player == "first") {
        int T;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;
            vector<vector<int>> neigh(n + 1);
            for (int i = 0; i < m; i++) {
                int a, b;
                cin >> a >> b;
                neigh[a].push_back(b);
                neigh[b].push_back(a);
            }
            vector dist(n + 1, Inf);
            dist[1] = 0;
            queue<int> Q;
            Q.push(1);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (auto& u : neigh[v])
                    if (dist[v] + 1 < dist[u]) {
                        dist[u] = dist[v] + 1;
                        Q.push(u);
                    }
            }
            string res(n, '?');
            for (int i = 1; i <= n; i++)
                res[i - 1] = rgb[dist[i] % rgb.length()];
            cout << res << "\n";
        }
    } else {
        int T;
        cin >> T;
        while (T--) {
            int q;
            cin >> q;
            while (q--) {
                int v;
                cin >> v;
                string s;
                cin >> s;
                int ind = 0;
                while (s.find(rgb[ind]) != string::npos)
                    ++ind;
                ind = (ind + 2) % rgb.length();
                int res = 0;
                for (int i = 0; i < s.length(); i++)
                    if (s[i] == rgb[ind]) {
                        res = i;
                        break;
                    }
                cout << res + 1 << "\n";
            }
        }
    }
    return 0;
}
