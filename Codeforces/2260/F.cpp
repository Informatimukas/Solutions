#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct UnionSet {
    vector<int> par, siz;
    UnionSet(int n): par(n + 1), siz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    bool unionSet(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return false;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        return true;
    }
};

struct node {
    vector<ii> neigh;
    int L{};
    ii par;
};

void Traverse(vector<node>& nodes, int v) {
    for (auto& [u, ind] : nodes[v].neigh) {
        if (u == nodes[v].par.first)
            continue;
        nodes[u].par = {v, ind};
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u);
    }
}

void Fill(const vector<node>& nodes, int v, const vector<bool>& forb, vector<bool>& tk) {
    if (tk[v])
        return;
    tk[v] = true;
    for (auto& [u, ind] : nodes[v].neigh) {
        if (forb[ind])
            continue;
        Fill(nodes, u, forb, tk);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        UnionSet US(n);
        vector<node> nodes(n + 1);
        vector<ii> edges(m);
        vector<int> spec;
        for (int i = 0; i < m; i++) {
            auto& [a, b] = edges[i];
            cin >> a >> b;
            if (US.unionSet(a, b)) {
                nodes[a].neigh.emplace_back(b, i);
                nodes[b].neigh.emplace_back(a, i);
            } else spec.push_back(i);
        }
        Traverse(nodes, 1);
        vector<int> has(m);
        for (int i = 0; i < spec.size(); i++) {
            has[spec[i]] |= 1 << i;
            auto [a, b] = edges[spec[i]];
            while (a != b) {
                if (nodes[a].L > nodes[b].L)
                    swap(a, b);
                has[nodes[b].par.second] |= 1 << i;
                b = nodes[b].par.first;
            }
        }
        for (auto ind : spec) {
            auto& [a, b] = edges[ind];
            nodes[a].neigh.emplace_back(b, ind);
            nodes[b].neigh.emplace_back(a, ind);
        }
        bool res = false;
        for (int i = 1; i < 1 << spec.size(); i++) {
            vector<bool> forb(m);
            for (int j = 0; j < m; j++)
                forb[j] = __builtin_popcount(has[j] & i) % 2;
            vector tk(n + 1, false);
            Fill(nodes, 1, forb, tk);
            if (all_of(tk.begin() + 1, tk.end(), [](auto&& x) { return x; })) {
                res = true;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << "\n";
    }
    return 0;
}
