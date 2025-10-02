#include <bits/stdc++.h>
using namespace std;

struct node {
    int low{0}, tim{0};
    vector<int> neigh;
    int comp;
    bool onStack{false};
    void addNode(int v) {
        if (v)
            neigh.push_back(v);
    }
};

int SCC(int v, vector<node>& nodes) {
    static int cur = 0;
    static vector<int> S;
    nodes[v].tim = nodes[v].low = ++cur;
    S.push_back(v);
    nodes[v].onStack = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    vector<int> need(m);
    for (auto& x : need)
        cin >> x;
    int N = 0;
    vector id(n, vector(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == '#')
                id[i][j] = ++N;
    vector<node> nodes(N);
    for (int j = 0; j < m; j++) {
        int lef = 0, mid = 0, rig = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (j && id[i][j - 1])
                lef = id[i][j - 1];
            if (j + 1 < m && id[i][j + 1])
                rig = id[i][j + 1];
            if (id[i][j]) {
                nodes[id[i][j]].addNode(lef);
                nodes[id[i][j]].addNode(mid);
                nodes[id[i][j]].addNode(rig);
                if (i)
                    nodes[id[i][j]].addNode(id[i - 1][j]);
                mid = id[i][j];
            }
        }
    }

    return 0;
}