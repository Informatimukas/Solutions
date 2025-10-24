#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr ll Inf = 1000000000000000000ll;

struct hull {
    vector<llll> lines;
    vector<ll> X;
    int pnt{0};
    static ll getX(const llll& line1, const llll& line2) {
        if (line1.second <= line2.second)
            return 0;
        if (line1.first >= line2.first)
            return Inf;
        return (line1.second - line2.second) / (line2.first - line1.first) + 1;
    }
    void addLine(llll line) {
        ll lstX = 0;
        while (!lines.empty()) {
            lstX = getX(lines.back(), line);
            if (lstX >= Inf)
                return;
            if (lstX > X.back())
                break;
            lstX = 0;
            lines.pop_back();
            X.pop_back();
        }
        X.push_back(lstX);
        lines.push_back(std::move(line));
    }
    ll getValue(ll x) {
        while (pnt + 1 < X.size() && X[pnt + 1] <= x)
            pnt++;
        return x * lines[pnt].first + lines[pnt].second;
    }
};

struct node {
    vector<int> neigh;
    ll A, B;
    bool spec{false};
    ll add{0};
    hull h;
    int cnt{0};
    int lef, rig;
    int ownedBy;
};

bool isAncestor(const vector<node>& tree, int ancestor, int child) {
    return tree[ancestor].lef <= tree[child].lef && tree[child].lef <= tree[ancestor].rig;
}

void Traverse(vector<node>& tree, int v) {
    static int cur = 0;
    tree[v].lef = ++cur;
    for (auto& u : tree[v].neigh) {
        tree[u].A += tree[v].A;
        tree[u].B += tree[v].B;
        Traverse(tree, u);
    }
    tree[v].rig = cur;
}

void markOwners(vector<node>& tree, int v) {
    if (tree[v].spec)
        tree[v].ownedBy = v;
    tree[tree[v].ownedBy].cnt++;
    for (auto& u : tree[v].neigh) {
        tree[u].ownedBy = tree[v].ownedBy;
        markOwners(tree, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<node> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].neigh.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> tree[i].A;
    for (int i = 1; i <= n; i++)
        cin >> tree[i].B;
    Traverse(tree, 1);
    vector<llll> seq(n);
    for (int i = 1; i <= n; i++) {
        tree[i].B = abs(tree[i].B);
        seq[i - 1] = {-tree[i].B, i};
    }
    ranges::sort(seq);
    vector<vector<int>> queries(q);
    for (auto& V : queries) {
        int typ, v;
        cin >> typ >> v;
        if (typ == 1) {
            int x;
            cin >> x;
            V = {v, x};
        } else V = {v};
    }
    int p = 5000;
    for (int i = 0; i < q; i += p) {
        int to = min(q, i + p);
        vector<int> specList;
        for (int j = i; j < to; j++) {
            int v = queries[j][0];
            if (!tree[v].spec) {
                specList.push_back(v);
                tree[v].spec = true;
            }
        }
        tree[1].ownedBy = 0;
        markOwners(tree, 1);
        for (auto& u : specList) {
            tree[u].h.lines.reserve(2 * tree[u].cnt);
            tree[u].h.X.reserve(2 * tree[u].cnt);
        }
        for (auto& v : seq | views::values) {
            auto root = tree[v].ownedBy;
            if (!root)
                continue;
            tree[root].h.addLine({-tree[v].B, -tree[v].A * tree[v].B});
        }
        for (auto& v : seq | views::reverse | views::values) {
            auto root = tree[v].ownedBy;
            if (!root)
                continue;
            tree[root].h.addLine({tree[v].B, tree[v].A * tree[v].B});
        }
        for (int j = i; j < to; j++) {
            int v = queries[j][0];
            if (queries[j].size() > 1) {
                int x = queries[j][1];
                for (auto& u : specList)
                    if (isAncestor(tree, v, u))
                        tree[u].add += x;
            } else {
                ll res = 0;
                for (auto& u : specList)
                    if (isAncestor(tree, v, u))
                        res = max(res, tree[u].h.getValue(tree[u].add));
                cout << res << "\n";
            }
        }
        for (int j = 1; j <= n; j++) {
            int root = tree[j].ownedBy;
            if (!root)
                continue;
            tree[j].A += tree[root].add;
        }
        for (auto& u : specList) {
            tree[u].spec = false;
            tree[u].add = 0;
            tree[u].cnt = 0;
            tree[u].h = hull();
        }
    }
    return 0;
}