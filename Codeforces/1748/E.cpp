#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxk = 20;
constexpr ll mod = 1000000007;

ii Better(ii a, ii b) {
    if (a.first != b.first)
        return a.first > b.first ? a : b;
    return a.second < b.second ? a : b;
}

int getMax(const vector<vector<ii>>& mx, int lef, int rig) {
    ii best = {0, 0};
    for (int i = Maxk - 1; i >= 0; i--)
        if (lef + (1 << i) <= rig + 1) {
            best = Better(best, mx[lef][i]);
            lef += 1 << i;
        }
    return best.second;
}

vector<ll> Solve(const vector<vector<ii>>& mx, int m, int lef, int rig) {
    vector<ll> res(m + 1);
    if (lef > rig) {
        ranges::fill(res, 1);
        return res;
    }
    int ind = getMax(mx, lef, rig);
    auto L = Solve(mx, m, lef, ind - 1);
    auto R = Solve(mx, m, ind + 1, rig);
    ll tot = 0;
    for (int i = 1; i <= m; i++) {
        tot = (tot + L[i - 1] * R[i]) % mod;
        res[i] = tot;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector mx(n, vector<ii>(Maxk));
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mx[i][0] = {a, i};
        }
        for (int j = 1; j < Maxk; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                mx[i][j] = Better(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
        auto res = Solve(mx, m, 0, n - 1);
        cout << res[m] << "\n";
    }
    return 0;
}
