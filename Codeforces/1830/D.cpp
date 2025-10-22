#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(map<int, ll>& M, int key, ll value) {
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        --it;
        if (it->second <= value)
            return;
        if (it->first != key)
            ++it;
    }
    while (it != M.end() && value <= it->second)
        M.erase(it++);
    M.emplace(key, value);
}

array<map<int, ll>, 2> Solve(int v, int p, const vector<vector<int>>& neigh) {
    array<map<int, ll>, 2> M{};
    Add(M[0], 1, 1);
    Add(M[1], 1, 2);
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        auto chM = Solve(u, v, neigh);
        array<map<int, ll>, 2> nM;
        for (int i = 0; i < 2; i++) {
            int mult = i == 0 ? 1 : 2;
            for (auto& [key, value] : M[i]) {
                Add(nM[i], key, value + chM[1 - i].rbegin()->second);
                for (auto& [key2, value2] : chM[i])
                    Add(nM[i], key + key2, value + value2 +
                        static_cast<ll>(key) * key2 * mult);
            }
        }
        M = std::move(nM);
    }
    return M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        auto got = Solve(1, 0, neigh);
        cout << static_cast<ll>(n) * (n + 1) -
            min(got[0].rbegin()->second, got[1].rbegin()->second) << "\n";
    }
    return 0;
}