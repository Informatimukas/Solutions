#include <bits/stdc++.h>
using namespace std;

array<bool, 3> Get(int v, int p, const vector<vector<int>>& neigh) {
    array<bool, 3> res{};
    if (neigh[v].size() - (p != 0) > 0) {
        res[0] = true;
        for (auto u : neigh[v]) {
            if (u == p)
                continue;
            array<bool, 3> nres{};
            auto got = Get(u, v, neigh);
            for (int i = 0; i < res.size(); i++)
                if (res[i])
                    for (int j = 0; j < got.size(); j++)
                        if (got[j])
                            nres[(i + j) % nres.size()] = true;
            res = nres;
        }
    }
    res[1] = true;
    return res;
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
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        auto res = Get(1, 0, neigh);
        cout << (res[0] ? "YES" : "NO") << "\n";
    }
    return 0;
}
