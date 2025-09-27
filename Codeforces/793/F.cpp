#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Get(const map<int, int>& M, int x) {
    auto it = M.upper_bound(x);
    if (it == M.begin())
        return x;
    return max(x, prev(it)->second);
}

void Insert(map<int, int>& M, int x, int y) {
    auto it = M.lower_bound(x);
    while (it != M.end() && y >= it->second)
        M.erase(it++);
    M.emplace(x, y);
}

int Query(const vector<map<int, int>>& st, int v, int l, int r, int a, int b, int best) {
    if (l == a && r == b)
        return Get(st[v], best);
    int m = (l + r) / 2;
    if (a <= m)
        best = Query(st, 2 * v, l, m, a, min(m, b), best);
    if (m + 1 <= b)
        best = Query(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, best);
    return best;
}

void Update(vector<map<int, int>>& st, int v, int l, int r, int x, int from, int to) {
    Insert(st[v], from, Get(st[v], to));
    if (l < r) {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, 2 * v, l, m, x, from, to);
        else Update(st, 2 * v + 1, m + 1, r, x, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector inByLef(n + 1, vector<int>());
    vector querByLef(n + 1, vector<int>());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        inByLef[l].push_back(r);
    }
    int q;
    cin >> q;
    vector<ii> queries(q);
    vector<int> res(q);
    for (int i = 0; i < queries.size(); i++) {
        cin >> queries[i].first >> queries[i].second;
        querByLef[queries[i].first].push_back(i);
    }
    vector<map<int, int>> st(4 * n);
    for (int l = n; l > 0; l--) {
        for (auto& r : inByLef[l]) {
            Update(st, 1, 1, n, r, l, r);
        }
        for (auto& qind : querByLef[l])
            res[qind] = Query(st, 1, 1, n, 1, queries[qind].second,
                queries[qind].first);
    }
    for (auto& r : res)
        cout << r << "\n";
    return 0;
}