#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector neigh(n + 1, set<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    int res = 0;
    while (true) {
        vector<int> seq;
        for (int i = 1; i <= n; i++)
            if (neigh[i].size() == 1)
                seq.push_back(i);
        if (seq.empty())
            break;
        res++;
        for (auto& x : seq)
            if (!neigh[x].empty()) {
                neigh[*neigh[x].begin()].erase(x);
                neigh[x].clear();
            }
    }
    cout << res << "\n";
    return 0;
}