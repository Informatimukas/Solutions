// Next steps: solve one SCC. I tried picking lowest indegree vertice and delete incoming
// and outgoing vertices, but it doesn't always work.
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<ii, int>;
using pq = priority_queue<iii, vector<iii>, greater<>>;

void Erase(int v, pq& Q, vector<vector<int>>& neigh, vector<int>& in, vector<bool>& rem,
    const vector<int>& comp) {
    for (auto& u : neigh[v]) {
        if (rem[u])
            continue;
        Q.push({{-comp[u], --in[u]}, u});
    }
    rem[v] = true;
}

void SCC(int v, vector<vector<int>>& neigh, vector<int>& tim, vector<int>& low,
    vector<int>& comp, vector<bool>& onStack,
    vector<int>& S) {
    static int cur = 0;
    static int curcomp = 0;
    tim[v] = low[v] = ++cur;
    S.push_back(v);
    onStack[v] = true;
    for (auto& u : neigh[v])
        if (!tim[u]) {
            SCC(u, neigh, tim, low, comp, onStack, S);
            low[v] = min(low[v], low[u]);
        } else if (onStack[u])
            low[v] = min(low[v], tim[u]);
    if (tim[v] == low[v]) {
        curcomp++;
        int u;
        do {
            u = S.back();
            onStack[u] = false;
            S.pop_back();
            comp[u] = curcomp;
        } while (u != v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector rem(n + 1, false);
    vector neigh(n + 1, vector<int>()), rneigh(n + 1, vector<int>());
    vector in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
        in[b]++;
    }
    vector low(n + 1, 0), tim(n + 1, 0), comp(n + 1, 0);
    vector onStack(n + 1, false);
    vector<int> S;
    for (int i = 1; i <= n; i++)
        if (!tim[i])
            SCC(i, neigh, tim, low, comp, onStack, S);
    vector<int> res;
    pq Q;
    for (int i = 1; i <= n; i++)
        Q.push({{-comp[i], in[i]}, i});
    while (!Q.empty()) {
        int v = Q.top().second;
        Q.pop();
        if (rem[v])
            continue;
        res.push_back(v);
        for (auto& u : neigh[v])
            if (!rem[u])
                Erase(u, Q, neigh, in, rem, comp);
        for (auto& u : rneigh[v])
            if (!rem[u])
                Erase(u, Q, neigh, in, rem, comp);
        rem[v] = true;
    }
    cout << res.size() << "\n";
    for (auto it = res.begin(); it != res.end(); ++it) {
        if (it != res.begin())
            cout << " ";
        cout << *it;
    }
    cout << "\n";
    return 0;
}
