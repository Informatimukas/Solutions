#include <bits/stdc++.h>
using namespace std;

constexpr int Maxk = 20;
constexpr int Inf = 1000000007;

int getMax(const vector<vector<int>>& mx, int lef, int rig) {
    int res = -Inf;
    for (int i = Maxk - 1; i >= 0; i--)
        if (lef + (1 << i) <= rig + 1) {
            res = max(res, mx[lef][i]);
            lef += 1 << i;
        }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int z = n - m + 1;
    vector mx(z, vector<int>(Maxk));
    for (int i = 0; i < z; i++)
        cin >> mx[i][0];
    for (int j = 1; j < Maxk; j++)
        for (int i = 0; i + (1 << j) <= z; i++)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
    int q;
    cin >> q;
    while (q--) {
        int lef, rig;
        cin >> lef >> rig;
        lef--;
        rig--;
        if (rig - lef + 1 < m) {
            cout << "unbounded\n";
            continue;
        }
        int got = getMax(mx, lef, rig - (m - 1));
        int res = got / m;
        if (got > 0 && res * m < got)
            res++;
        cout << res << "\n";
    }
    return 0;
}
