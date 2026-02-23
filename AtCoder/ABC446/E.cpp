#include <bits/stdc++.h>
using namespace std;

bool Solve(int i, int j, int m, int a, int b, vector<vector<bool>>& taken, vector<vector<bool>>& good) {
    if (taken[i][j])
        return good[i][j];
    taken[i][j] = true;
    if (i == 0 || j == 0)
        return false;
    good[i][j] = true;
    int k = (a * j + b * i) % m;
    int ni = j, nj = k;
    return good[i][j] = Solve(ni, nj, m, a, b, taken, good);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b;
    cin >> m >> a >> b;
    vector taken(m, vector(m, false));
    vector good(m, vector(m, false));
    int res = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (!taken[i][j])
                Solve(i, j, m, a, b, taken, good);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            res += good[i][j];
    cout << res << "\n";
    return 0;
}
