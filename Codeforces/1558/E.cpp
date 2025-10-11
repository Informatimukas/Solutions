#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int lim = 1000000007;

struct node {
    int a{0}, b{0};
    int mema, memb;
    vector<int> neigh;
};

bool Traverse(vector<node>& nodes, int v, int p, ll cur, int cnt, vector<int>& tk,
    vector<int>& par, vector<ll>& best, bool update, ll& resCur, int& resRem) {
    if (tk[v] == 1) {
        if (cnt == 0)
            return false;
        if (update) {
            resCur = cur;
            resRem -= cnt;
            int u = p;
            nodes[u].a = nodes[u].b = 0;
            while (u != v) {
                u = par[u];
                nodes[u].a = nodes[u].b = 0;
            }
        }
        return true;
    }
    if (tk[v] == 2 && best[v] >= cur || cur <= nodes[v].a)
        return false;
    tk[v] = 1;
    best[v] = cur;
    par[v] = p;
    if (nodes[v].a > 0) {
        cur += nodes[v].b;
        cnt++;
    }
    for (auto& u : nodes[v].neigh) {
        if (u == p)
            continue;
        if (Traverse(nodes, u, v, cur, cnt, tk, par, best,
            update, resCur, resRem))
            return true;
    }
    tk[v] = 2;
    return false;
}

bool Check(vector<node>& nodes, bool update, ll& cur, int& rem) {
    vector tk(nodes.size(), 0);
    vector<int> par(nodes.size());
    vector<ll> best(nodes.size());
    return Traverse(nodes, 1, 0, cur, 0, tk, par, best, update, cur, rem);
}

bool canSolve(vector<node>& nodes, ll cur) {
    int rem = nodes.size() - 2;
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].a = nodes[i].mema;
        nodes[i].b = nodes[i].memb;
    }
    while (rem > 0)
        if (!Check(nodes, true, cur, rem))
            return false;
    return true;
}

ll Solve(vector<node>& nodes) {
    ll lef = 0, rig = lim;
    while (lef <= rig) {
        ll mid = (lef + rig) / 2;
        if (canSolve(nodes, mid))
            rig = mid - 1;
        else lef = mid + 1;
    }
    return lef;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<node> nodes(n + 1);
        for (int i = 2; i <= n; i++)
            cin >> nodes[i].a;
        for (int i = 2; i <= n; i++) {
            cin >> nodes[i].b;
            nodes[i].mema = nodes[i].a;
            nodes[i].memb = nodes[i].b;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        cout << Solve(nodes) << "\n";
    }
    return 0;
}