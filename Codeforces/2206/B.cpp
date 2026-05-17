#include <bits/stdc++.h>
using namespace std;

int Solve(int v, const vector<vector<int>>& neigh, bool first) {
    if (neigh[v].empty())
        return v;
    bool nfirst = neigh[v].size() % 2 == 0 ? !first : first;
    deque<int> D;
    for (auto u : neigh[v])
        D.push_back(Solve(u, neigh, nfirst));
    ranges::sort(D);
    while (D.size() > 1) {
        if (first)
            D.pop_back();
        else D.pop_front();
        first = !first;
    }
    return D[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> neigh(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        neigh[p].push_back(i);
    }
    cout << Solve(1, neigh, true) << "\n";
    return 0;
}
