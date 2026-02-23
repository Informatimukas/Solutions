#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector neigh(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
    }
    vector tk(n + 1, false);
    int tkcnt = 0;
    set<int> S;
    S.insert(1);
    for (int i = 1; i <= n; i++) {
        if (S.contains(i)) {
            S.erase(i);
            tk[i] = true;
            tkcnt++;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (auto u : neigh[v])
                    if (u <= i) {
                        if (!tk[u]) {
                            tk[u] = true;
                            tkcnt++;
                            Q.push(u);
                        }
                    } else S.insert(u);
            }
        }
        cout << (tkcnt < i ? -1 : static_cast<int>(S.size())) << "\n";
    }
    return 0;
}
