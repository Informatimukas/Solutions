#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

struct node {
    int col;
    vector<int> neigh;
};

void addBest(array<int, 2>& best, int val) {
    if (val < best[0])
        best[1] = best[0], best[0] = val;
    else if (val < best[1])
        best[1] = val;
}

int Solve(int v, int p, const vector<node>& nodes, int x, int& res) {
    array best{Inf, Inf};
    if (nodes[v].col <= x)
        addBest(best, 0);
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        addBest(best, Solve(u, v, nodes, x, res) + 1);
    }
    res = min(res, best[0] + best[1]);
    return best[0];
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
        vector<node> nodes(n + 1);
        int c0;
        cin >> c0;
        nodes[c0].col = 0;
        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;
            nodes[a].col = i;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        vector<int> res(n);
        int cur = 0;
        while (cur < n) {
            int got = Inf;
            Solve(1, 0, nodes, cur, got);
            int lef = cur + 1, rig = n - 1;
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                int ch = Inf;
                Solve(1, 0, nodes, mid, ch);
                if (ch == got)
                    lef = mid + 1;
                else rig = mid - 1;
            }
            while (cur < lef)
                res[cur++] = got;
        }
        for (int i = 1; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
