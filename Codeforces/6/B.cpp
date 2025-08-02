#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<string> B(n);
    for (auto& el : B)
        cin >> el;
    vector<ii> dp = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<char> S;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == c) {
                for (auto& [dx, dy]: dp) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        if (B[ni][nj] != c && B[ni][nj] != '.')
                            S.insert(B[ni][nj]);
                }
            }
    cout << S.size() << "\n";
    return 0;
}
