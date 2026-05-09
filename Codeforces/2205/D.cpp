#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxm = 20;

ii getMax(const vector<vector<ii>>& mx, int lef, int rig) {
    ii res = {0, 0};
    for (int i = Maxm - 1; i >= 0; i--)
        if (lef + (1 << i) <= rig + 1) {
            res = max(res, mx[lef][i]);
            lef += 1 << i;
        }
    return res;
}

int Solve(const vector<vector<ii>>& mx, int lef, int rig) {
    if (lef > rig)
        return 0;
    int m = getMax(mx, lef, rig).second;
    return 1 + max(Solve(mx, lef, m - 1), Solve(mx, m + 1, rig));
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
        vector<int> a(n);
        vector mx(n, vector<ii>(Maxm));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx[i][0] = {a[i], i};
        }
        for (int j = 1; j < Maxm; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
        cout << n - Solve(mx, 0, n - 1) << "\n";
    }
    return 0;
}
