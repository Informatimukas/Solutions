#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector dx = {-1, 0, 1, 0};
    const vector dy = {0, -1, 0, 1};
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    set<ii> S;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == 'P')
                for (int d = 0; d < dx.size(); d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && B[ni][nj] == 'W')
                        S.emplace(ni, nj);
                }
    cout << S.size() << "\n";
    return 0;
}
