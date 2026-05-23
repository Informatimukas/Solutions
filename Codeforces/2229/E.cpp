#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<set<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        int global = 0;
        vector my(n + 1, 0);
        priority_queue<int, vector<int>, greater<>> Q;
        int mx = 0;
        for (int i = 1; i <= n; i++)
            if (neigh[i].size() == 1) {
                Q.push(i);
                mx = i;
            }
        my[mx] = 1;
        while (Q.top() != mx) {
            int v = Q.top();
            Q.pop();
            for (auto u : neigh[v]) {
                neigh[u].erase(v);
                if (neigh[u].size() == 1)
                    Q.push(u);
            }
            neigh[v].clear();
        }
        while (Q.size() > 1) {
            int v = Q.top();
            Q.pop();
            int cur = (global + my[v]) % mod;
            global = (global + cur) % mod;
            for (auto u : neigh[v]) {
                neigh[u].erase(v);
                if (neigh[u].size() == 1) {
                    Q.push(u);
                    my[u] = (my[u] - global + mod) % mod;
                }
            }
            neigh[v].clear();
        }
        int res = (global + my[Q.top()]) % mod;
        cout << res << "\n";
    }
    return 0;
}
