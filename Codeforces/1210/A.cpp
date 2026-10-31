#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxd = 6;

int Gen(int lvl, int lim, vector<int>& a, const vector<ii>& edges) {
    if (lvl > lim) {
        array<array<int, Maxd + 1>, Maxd + 1> tk{};
        int res = 0;
        for (auto [u, v] : edges) {
            u = a[u], v = a[v];
            if (u > v)
                swap(u, v);
            if (!tk[u][v]) {
                tk[u][v] = true;
                res++;
            }
        }
        return res;
    }
    int res = 0;
    for (int i = 1; i <= Maxd; i++) {
        a[lvl] = i;
        res = max(res, Gen(lvl + 1, lim, a, edges));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ii> seq(m);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    vector<int> a(n + 1);
    cout << Gen(1, n, a, seq) << "\n";
    return 0;
}
