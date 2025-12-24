#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct node {
    vector<int> neigh;
    vector<int> my, cur;
    int siz{0};
    bool er{false};
    int col{0};
};

vector<int> Merge(const vector<int>& A, const vector<int>& B) {
    vector<int> res(min(A.size(), B.size()));
    int pnt = 0;
    auto it1 = A.begin(), it2 = B.begin();
    while (it1 != A.end() && it2 != B.end())
        if (*it1 == *it2) {
            res[pnt++] = *it1++;
            ++it2;
        } else if (*it1 > *it2)
            it2 = lower_bound(it2, B.end(), *it1);
        else it1 = lower_bound(it1, A.end(), *it2);
    res.resize(pnt);
    return res;
}

void Count(vector<node>& nodes, int v, int p) {
    nodes[v].siz = 1;
    for (auto& u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        Count(nodes, u, v);
        nodes[v].siz += nodes[u].siz;
    }
}

int getCentroid(const vector<node>& nodes, int v, int p, int lim) {
    for (auto& u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        if (nodes[u].siz > lim)
            return getCentroid(nodes, u, v, lim);
    }
    return v;
}

void Traverse(vector<node>& nodes, int v, int p, int c) {
    nodes[v].cur = Merge(nodes[v].my, nodes[p].cur);
    nodes[v].col = c;
    for (auto& u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        Traverse(nodes, u, v, c);
    }
}

void Solve(vector<node>& nodes, int v, map<ii, int>& M, const vector<ii>& seq) {
    if (seq.empty())
        return;
    Count(nodes, v, 0);
    int C = getCentroid(nodes, v, 0, nodes[v].siz / 2);
    vector<vector<ii>> nxtSeq(nodes[C].neigh.size() + 1);
    nodes[C].col = nodes[C].neigh.size();
    nodes[C].cur = nodes[C].my;
    for (int i = 0; i < nodes[C].neigh.size(); i++) {
        int u = nodes[C].neigh[i];
        if (nodes[u].er)
            continue;
        Traverse(nodes, u, C, i);
    }
    for (auto& p : seq)
        if (nodes[p.first].col == nodes[p.second].col)
            nxtSeq[nodes[p.first].col].push_back(p);
        else M.find(p)->second = Merge(nodes[p.first].cur, nodes[p.second].cur).size();
    nodes[C].er = true;
    for (int i = 0; i < nodes[C].neigh.size(); i++) {
        int u = nodes[C].neigh[i];
        if (nodes[u].er)
            continue;
        Solve(nodes, u, M, nxtSeq[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, s, q;
        cin >> n >> k >> s >> q;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        for (int i = 0; i < s; i++) {
            int v, x;
            cin >> v >> x;
            nodes[v].my.push_back(x);
        }
        for (int i = 1; i <= n; i++)
            ranges::sort(nodes[i].my);
        map<ii, int> M;
        vector<ii> seq;
        vector<ii> queries(q);
        for (auto& [u, v] : queries) {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            if (u == v)
                M.insert({{u, v}, static_cast<int>(nodes[u].my.size())});
            else if (M.insert({{u, v}, 0}).second)
                seq.emplace_back(u, v);
        }
        Solve(nodes, 1, M, seq);
        for (int i = 0; i < queries.size(); i++)
            cout << M.find(queries[i])->second << (i + 1 < queries.size() ? ' ' : '\n');
    }
    return 0;
}
