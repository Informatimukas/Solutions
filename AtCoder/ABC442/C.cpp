#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector neigh(n + 1, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        ll rem = n - 1 - neigh[i].size();
        ll res = rem * (rem - 1) * (rem - 2) / 6;
        cout << res << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}