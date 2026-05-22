#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int> neigh;
};

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
    vector seq(S.begin(), S.end());
    int lef = 0, rig = seq.size() - 1;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        if (Traverse(nodes, 1, seq[mid]) > 0)
            lef = mid + 1;
        else rig = mid - 1;
    }
    cout << seq[lef] << "\n";
    return 0;
}
