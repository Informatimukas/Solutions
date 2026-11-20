#include <bits/stdc++.h>
using namespace std;

int Solve(int v, const vector<vector<int>>& neigh) {
    priority_queue<int, vector<int>, greater<>> Q;
    for (auto u : neigh[v])
        Q.push(Solve(u, neigh));
    if (Q.empty())
        return 0;
    if (Q.size() == 1)
        return Q.top() + 1;
    while (Q.size() > 1) {
        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();
        Q.push(b + 1);
    }
    return Q.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> neigh(n + 1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
        }
        cout << Solve(1, neigh) << "\n";
    }
    return 0;
}
