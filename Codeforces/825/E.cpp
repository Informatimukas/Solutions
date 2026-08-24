#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> neigh(n + 1);
    vector in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[a]++;
        neigh[b].push_back(a);
    }
    priority_queue<int> Q;
    int pnt = n;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        int v = Q.top();
        Q.pop();
        res[v] = pnt--;
        for (auto u : neigh[v])
            if (--in[u] == 0)
                Q.push(u);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
