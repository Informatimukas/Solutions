#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector res(n, vector(n, 0));
    int r = 0, c = (n - 1) / 2;
    res[r][c] = 1;
    for (int i = 2; i <= n * n; i++) {
        int nr = (r - 1 + n) % n;
        int nc = (c + 1) % n;
        if (!res[nr][nc])
            res[nr][nc] = i;
        else {
            nr = (r + 1) % n;
            nc = c;
            res[nr][nc] = i;
        }
        r = nr;
        c = nc;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << res[i][j] << (j + 1 < n? ' ' : '\n');
    return 0;
}
