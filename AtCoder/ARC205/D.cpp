#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Traverse(int v, const vector<vector<int>>& neigh, vector<int>& cnt) {
    cnt[v] = 1;
    for (auto& u : neigh[v]) {
        Traverse(u, neigh, cnt);
        cnt[v] += cnt[u];
    }
}

int Solve(int v, const vector<vector<int>>& neigh, const vector<int>& cnt) {
    int sum = 0;
    ii mx = {0, 0};
    for (auto& u : neigh[v]) {
        sum += cnt[u];
        mx = max(mx, {cnt[u], u});
    }
    if (sum == 0) return 0;
    int got = Solve(mx.second, neigh, cnt);
    if (2 * (mx.first - 2 * got) <= sum - 2 * got)
        return sum / 2;
    return sum - mx.first + got;
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
        vector neigh(n + 1, vector<int>());
        vector cnt(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
        }
        Traverse(1, neigh, cnt);
        cout << Solve(1, neigh, cnt) << "\n";
    }
    return 0;
}
