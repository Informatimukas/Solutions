#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Update(vector<string>& B, vector<string>& res, int r, int c) {
    const vector<ii> dirs = {{0, 0}, {-1, 0}, {0, -1},
        {1, 0}, {0, 1}};
    int n = B.size();
    int m = B[0].size();
    res[r][c] = 'S';
    for (auto& p : dirs) {
        int nr = r + p.first;
        int nc = c + p.second;
        if (0 <= nr && nr < n && 0 <= nc && nc < m)
            if (B[nr][nc] == '#')
                B[nr][nc] = '.';
    }
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
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        vector<string> res = B;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (B[i][j] == '#') {
                    if (i + 1 < n && j + 1 < m && B[i][j + 1] == '#' && B[i + 1][j] == '#') {
                        Update(B, res, i, j);
                        continue;
                    }
                    if (j + 1 < m && B[i][j + 1] == '#') {
                        Update(B, res, i, j + 1);
                        continue;
                    }
                    if (i + 1 < n && B[i + 1][j] == '#') {
                        Update(B, res, i + 1, j);
                        continue;
                    }
                    Update(B, res, i, j);
                }
        for (auto& x : res)
            cout << x << "\n";
    }
    return 0;
}
