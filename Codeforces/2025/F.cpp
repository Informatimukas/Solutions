#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Traverse(int v, const vector<vector<ii>>& neigh, vector<int>& tk,
    vector<vector<int>>& my) {
    tk[v] = 1;
    int cur = 0;
    for (auto& [u, e] : neigh[v]) {
        if (tk[u] == 1)
            continue;
        if (tk[u] == 2) {
            my[v].push_back(e);
            cur ^= 1;
            continue;
        }
        auto got = Traverse(u, neigh, tk, my);
        if (got == 1)
            my[u].push_back(e);
        else {
            my[v].push_back(e);
            cur ^= 1;
        }
    }
    tk[v] = 2;
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ii> E(q);
    vector neigh(n + 1, vector<ii>());
    vector tk(n + 1, 0);
    vector my(n + 1, vector<int>());
    vector<string> res(q);
    for (int i = 0; i < q; i++) {
        auto& [a, b] = E[i];
        cin >> a >> b;
        neigh[a].emplace_back(b, i);
        neigh[b].emplace_back(a, i);
    }
    for (int i = 1; i <= n; i++)
        if (!tk[i])
            Traverse(i, neigh, tk, my);
    for (int i = 1; i <= n; i++) {
        ranges::sort(my[i]);
        for (int j = 0; j < my[i].size(); j++) {
            int ind = my[i][j];
            string res1 = E[ind].first == i ? "x" : "y";
            string res2 = j % 2 ? "-" : "+";
            res[ind] = res1 + res2;
        }
    }
    for (auto& x : res)
        cout << x << "\n";
    return 0;
}
