#include <bits/stdc++.h>
using namespace std;

struct node {
    int rig;
    int par, siz;
    int low;
    int cur;
};

int getPar(vector<node>& nodes, int v) {
    return nodes[v].par == v ? v : nodes[v].par = getPar(nodes, nodes[v].par);
}

void Progress(node& v, int to, vector<int>& res) {
    int add = to - v.low;
    cout << "move from " << v.low << " to " << to << endl;
    v.low = to;
    if (v.cur == 0)
        return;
    cout << "interval " << v.rig + 1 - v.cur << " " << v.rig << endl;
    res[v.rig + 1 - v.cur] += add;
    if (v.rig + 1 < res.size())
        res[v.rig + 1] -= add;
}

void unionSet(vector<node>& nodes, int a, int b, int to, vector<int>& res) {
    a = getPar(nodes, a);
    b = getPar(nodes, b);
    Progress(nodes[a], to, res);
    Progress(nodes[b], to, res);
    if (nodes[a].siz < nodes[b].siz)
        swap(a, b);
    nodes[a].rig = max(nodes[a].rig, nodes[b].rig);
    nodes[b].par = a;
    nodes[a].siz += nodes[b].siz;
    nodes[a].cur += nodes[b].cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i].rig = nodes[i].par = i;
        nodes[i].siz = nodes[i].cur = 1;
        nodes[i].low = 0;
    }
    vector res(n + 1, 0);
    vector A(n + 1, vector<int>());
    vector B(n, vector<int>());
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        A[a].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        B[b].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (auto& ind : A[i]) {
            int p = getPar(nodes, ind);
            nodes[p].cur--;
        }
        for (auto& ind : B[i])
            unionSet(nodes, ind, ind + 1, i, res);
    }
    int root = getPar(nodes, 1);
    Progress(nodes[root], n, res);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += res[i];
        cout << cur << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
