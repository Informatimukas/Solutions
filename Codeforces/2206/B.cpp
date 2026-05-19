#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int> neigh;
    int lef{}, rig{};
};

int Solve(int v, const vector<vector<int>>& neigh, bool first) {
    if (neigh[v].empty())
        return v;
    bool nfirst = neigh[v].size() % 2 == 0 ? !first : first;
    deque<int> D;
    for (auto u : neigh[v])
        D.push_back(Solve(u, neigh, nfirst));
    ranges::sort(D);
    while (D.size() > 1) {
        if (first)
            D.pop_back();
        else D.pop_front();
        first = !first;
    }
    return D[0];
}

void Mark(vector<node>& nodes, int v) {
    static int cur = 0;
    nodes[v].lef = ++cur;
    for (auto u : nodes[v].neigh)
        Mark(nodes, u);
    nodes[v].rig = cur;
}

int Traverse(const vector<node>& nodes, int v, int x) {
    if (nodes[v].neigh.empty())
        return v > x ? 1 : -1;
    int res = 0;
    for (auto u : nodes[v].neigh)
        res += Traverse(nodes, u, x);
    if (res > 0)
        res = 1;
    else if (res < 0)
        res = -1;
    return res;
}

int getStatus(const vector<node>& nodes, int v, int x) {
    if (v == x)
        return 0;
    int res = 0;
    for (auto u : nodes[v].neigh)
        if (nodes[u].lef <= nodes[x].lef && nodes[x].lef <= nodes[u].rig)
            res += getStatus(nodes, u, x);
        else res += Traverse(nodes, u, x);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    set S = {1};
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        S.erase(p);
        S.insert(i);
        nodes[p].neigh.push_back(i);
    }
    Mark(nodes, 1);
    vector seq(S.begin(), S.end());
    int lef = 0, rig = seq.size() - 1;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        int st = getStatus(nodes, 1, seq[mid]);
        if (st > 1)
            lef = mid + 1;
        else if (st < 0)
            rig = mid - 1;
        else {
            cout << seq[mid] << "\n";
            return 0;
        }
    }
    return 0;
}
