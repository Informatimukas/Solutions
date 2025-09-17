#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxval = 100005;
constexpr int Maxk = 20;

struct Tree {
    vector<int> a;
    vector<vector<int>> neigh;
    vector<vector<int>> P;
    vector<int> L;
    vector<int> lef, rig;
    Tree(int n): a(n + 1), neigh(n + 1), P(n + 1, vector(Maxk, 0)),
        L(n + 1), lef(n + 1), rig(n + 1) {}
};

struct Values {
    vector<vector<int>> bya;
    vector<int> pw1;
    vector<bool> isBig;
    int mod1;
    Values(): bya(Maxval), pw1(Maxval), isBig(Maxval) {}
};

struct Path {
    int a, b, lca, plca;
};

struct Query {
    Path p1, p2;
    int need;
    vector<int> res;
};

void Traverse(Tree& tree, int v) {
    static int cur = 0;
    tree.lef[v] = ++cur;
    for (auto& u : tree.neigh[v]) {
        if (u == tree.P[v][0])
            continue;
        tree.P[u][0] = v;
        tree.L[u] = tree.L[v] + 1;
        Traverse(tree, u);
    }
    tree.rig[v] = cur;
}

int getLCA(const Tree& tree, int a, int b) {
    if (tree.L[a] < tree.L[b])
        swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (tree.L[a] - (1 << i) >= tree.L[b])
            a = tree.P[a][i];
    if (a == b) return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (tree.P[a][i] != tree.P[b][i])
            a = tree.P[a][i], b = tree.P[b][i];
    return tree.P[a][0];
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void countSeq(const Tree& tree, int v, vector<int>& seq, int val, int curCount) {
    if (tree.a[v] == val)
        curCount++;
    seq[v] = curCount;
    for (auto& u : tree.neigh[v]) {
        if (u == tree.P[v][0])
            continue;
        countSeq(tree, u, seq, val, curCount);
    }
}

int getFromCountSeq(const Path& path, const vector<int>& seq) {
    return seq[path.a] + seq[path.b] - seq[path.lca] - seq[path.plca];
}

void solveBig(int val, const Tree& tree, vector<Query>& queries) {
    vector<int> seq(tree.a.size());
    countSeq(tree, 1, seq, val, 0);
    for (auto& x : queries)
        if (x.res.size() < x.need)
            if (getFromCountSeq(x.p1, seq) != getFromCountSeq(x.p2, seq))
                x.res.push_back(val);
}

void addSeq(const Tree& tree, int v, int lef, int rig,
    const Values& values, vector<int>& seq, int curAdd) {
    if (lef <= tree.a[v] && tree.a[v] <= rig && !values.isBig[tree.a[v]])
        curAdd = (curAdd + values.pw1[tree.a[v]]) % values.mod1;
    seq[v] = curAdd;
    for (auto& u : tree.neigh[v]) {
        if (u == tree.P[v][0])
            continue;
        addSeq(tree, u, lef, rig, values, seq, curAdd);
    }
}

int getFromAddSeq(const Path& path, const vector<int>& seq, int mod) {
    int res = (seq[path.a] + seq[path.b]) % mod;
    res = (res - seq[path.lca] + mod) % mod;
    res = (res - seq[path.plca] + mod) % mod;
    return res;
}

bool isSubtree(const Tree& tree, int a, int b) {
    return tree.lef[a] <= tree.lef[b] && tree.lef[b] <= tree.rig[a];
}

int checkOnPath(const Tree& tree, const Path& path, int v) {
    return isSubtree(tree, path.lca, v) &&
        (isSubtree(tree, v, path.a) || isSubtree(tree, v, path.b));
}

void solveSmall(int lef, int rig, const Tree& tree, vector<Query>& queries,
    const Values& values) {
    vector<int> seq(tree.a.size());
    addSeq(tree, 1, lef, rig, values, seq, 0);
    for (auto& x : queries)
        if (x.res.size() < x.need &&
            getFromAddSeq(x.p1, seq, values.mod1) != getFromAddSeq(x.p2, seq, values.mod1))
            for (int i = lef; i <= rig && x.res.size() < x.need; i++)
                if (!values.isBig[i]) {
                    int dif = 0;
                    for (auto& v : values.bya[i])
                        dif += checkOnPath(tree, x.p1, v) - checkOnPath(tree, x.p2, v);
                    if (dif != 0)
                        x.res.push_back(i);
                }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    Values values;
    values.mod1 = uniform_int_distribution(100000000, 1000000000)(rng);
    int arg1 = uniform_int_distribution(1000000, 10000000)(rng);
    while (!Prime(values.mod1)) values.mod1++;
    while (!Prime(arg1)) arg1++;
    values.pw1[0] = 1;
    for (int i = 1; i < values.pw1.size(); i++)
        values.pw1[i] = static_cast<ll>(values.pw1[i - 1]) * arg1 % values.mod1;
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 1; i <= n; i++) {
        cin >> tree.a[i];
        values.bya[tree.a[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree.neigh[a].push_back(b);
        tree.neigh[b].push_back(a);
    }
    Traverse(tree, 1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            tree.P[i][j] = tree.P[tree.P[i][j - 1]][j - 1];
    int Maxp = max(static_cast<int>(sqrt(n)) / 10, 1);
    for (int i = 0; i < values.pw1.size(); i++)
        values.isBig[i] = values.bya[i].size() >= Maxp;
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (auto& x : queries) {
        cin >> x.p1.a >> x.p1.b >> x.p2.a >> x.p2.b >> x.need;
        x.p1.lca = getLCA(tree, x.p1.a, x.p1.b);
        x.p2.lca = getLCA(tree, x.p2.a, x.p2.b);
        x.p1.plca = tree.P[x.p1.lca][0];
        x.p2.plca = tree.P[x.p2.lca][0];
    }
    int nxt = 1, cnt = 0;
    for (int i = 1; i < Maxval; i++) {
        if (values.isBig[i]) {
            solveBig(i, tree, queries);
            continue;
        }
        cnt += values.bya[i].size();
        if (cnt >= Maxp || cnt - nxt + 1 >= Maxp) {
            solveSmall(nxt, i, tree, queries, values);
            nxt = i + 1;
            cnt = 0;
        }
    }
    if (cnt > 0)
        solveSmall(nxt, Maxval - 1, tree, queries, values);
    for (auto& x : queries) {
        cout << x.res.size();
        for (auto& val : x.res)
            cout << " " << val;
        cout << "\n";
    }
    return 0;
}