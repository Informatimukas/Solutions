#include <bits/stdc++.h>
using namespace std;

int Ask(const vector<int>& seq) {
    cout << "? 1 " << seq.size();
    for (auto& x : seq)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void Toggle(int v)
{
    cout << "? 2 " << v << endl;
}

void Print(const vector<int>& res)
{
    cout << "!";
    for (int i = 1; i <= res.size(); i++)
        cout << " " << res[i];
    cout << endl;
}

void simpleSolve(int v, int fp, vector<vector<int>>& neigh, vector<int>& res) {
    int fv = Ask({v});
    res[v] = fv - fp;
    for (auto& u : neigh[v]) {
        neigh[u].erase(ranges::find(neigh[u], v));
        simpleSolve(u, fv, neigh, res);
    }
}

void Count(int v, int p, const vector<vector<int>>& neigh, vector<int>& cnt) {
    cnt[v] = 1;
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        Count(u, v, neigh, cnt);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, const vector<vector<int>>& neigh, vector<int>& cnt, int lim) {
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        if (cnt[u] > lim)
            return getCentroid(u, v, neigh, cnt, lim);
    }
    return v;
}

void Solve(int v, vector<vector<int>>& neigh, vector<int>& res) {
    static vector<int> cnt(neigh.size());
    Count(v, 0, neigh, cnt);
    v = getCentroid(v, 0, neigh, cnt, cnt[v] / 2);
    if (neigh[v].empty()) {
        res[v] = Ask({v});
        return;
    }
    int lef = 0, rig = neigh[v].size() - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        vector<int> tk;
        copy(neigh[v].begin(), neigh[v].begin() + mid + 1, back_inserter(tk));
        int old = Ask(tk);
        Toggle(v);
        int nw = Ask(tk);
        if (abs(old - nw) == mid + 1)
            lef = mid + 1;
        else rig = mid - 1;
    }
    if (lef >= neigh[v].size()) {
        int old = Ask({v});
        Toggle(v);
        int nw = Ask({v});
        res[v] = old < nw ? 1 : -1;
        for (auto& u : neigh[v]) {
            neigh[u].erase(ranges::find(neigh[u], v));
            simpleSolve(u, nw, neigh, res);
        }
        return;
    }
    int u = neigh[v][lef];
    int fu = Ask({u});
    neigh[v].erase(neigh[v].begin() + lef);
    simpleSolve(v, fu, neigh, res);
    neigh[u].erase(ranges::find(neigh[u], v));
    Solve(u, neigh, res);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector neigh(n + 1, vector<int>());
        vector<int> res(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Solve(1, neigh, res);
        Print(res);
    }
    return 0;
}
