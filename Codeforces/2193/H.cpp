#include <bits/stdc++.h>
using namespace std;

void Traverse2(int v, int p, const vector<int>& a, const vector<vector<int>>& neigh, vector<int>& tk, vector<int>& res) {
    if (a[v] % 2 == 0 || tk[v] == 2)
        return;
    tk[v] = 2;
    res.push_back(v);
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        Traverse2(u, v, a, neigh, tk, res);
    }
}

int Traverse1(int v, int p, const vector<int>& a, const vector<vector<int>>& neigh, vector<int>& tk, vector<int>& res) {
    if (a[v] % 2 == 0)
        return 0;
    tk[v] = 1;
    int got = p != 0;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        got += Traverse1(u, v, a, neigh, tk, res);
    }
    if (got % 2 == 0)
        Traverse2(v, p, a, neigh, tk, res);
    return got % 2;
}

vector<int> Solve(int n, const vector<int>& a, const vector<vector<int>>& neigh) {
    vector<int> res;
    vector tk(a.size(), 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] % 2) {
            ++cnt;
            if (tk[i] == 0)
                Traverse1(i, 0, a, neigh, tk, res);
        }
    if (cnt != res.size())
        return {};
    vector<int> my(n + 1);
    for (int i = 0; i < res.size(); i++)
        my[res[i]] = i;
    vector<vector<int>> bef(res.size());
    for (int i = 1; i <= n; i++)
        if (a[i] % 2 == 0) {
            int lst = -1;
            for (auto u : neigh[i])
                if (a[u] % 2)
                    lst = max(lst, my[u]);
            if (lst == -1)
                return {};
            bef[lst].push_back(i);
        }
    vector<int> ans;
    for (int i = 0; i < res.size(); i++) {
        for (auto b : bef[i])
            ans.push_back(b);
        ans.push_back(res[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        auto res = Solve(n, a, neigh);
        if (res.empty()) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
