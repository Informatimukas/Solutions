#include <bits/stdc++.h>
using namespace std;

int best = 0;

void Gen(vector<vector<bool>>& B, int r, int c, int n, int m, int mx) {
    if (mx <= best)
        return;
    if (r >= n) {
        best = mx;
        return;
    }
    if (c >= m) {
        Gen(B, r + 1, 0, n, m, mx);
        return;
    }
    if (B[r][c]) {
        Gen(B, r, c + 1, n, m, mx);
        return;
    }
    for (int s = 1; r + s < n && c + s < m; s++)
        if (!B[r + s][c] && !B[r][c + s] && !B[r + s][c + s]) {
            B[r + s][c] = B[r][c + s] = B[r + s][c + s] = true;
            Gen(B, r, c + 1, n, m, mx);
            B[r + s][c] = B[r][c + s] = B[r + s][c + s] = false;
        }
    Gen(B, r, c + 1, n, m, mx - 1);
}

void Solve(int off, int n, vector<array<int, 3>>& res) {
    res.push_back({off, off, n - 1});
    int tims = n / 2 - 1;
    for (int i = 0; i < tims; i++) {
        res.push_back({2 * i + 1 + off, off, 1});
        res.push_back({2 * i + 2 + off, n - 2 + off, 1});
        res.push_back({off, 2 * i + 2 + off, 1});
        res.push_back({n - 2 + off, 2 * i + 1 + off, 1});
    }
    if (n > 5)
        Solve(off + 2, n - 4, res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*for (int n = 9; n <= 9; n++)
        for (int m = n; m <= 9; m++) {
            best = 0;
            vector B(n, vector(m, false));
            Gen(B, 0, 0, n, m, n * m);
            if (best != (n / 2 * 2) * (m / 2 * 2))
                cout << "n = " << n << ", m = " << m << ", best = " << best << endl;
        }
    cout << "finished" << endl;
    return 0;*/
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> res;
        if (n % 2 == 0 || m % 2 == 0 || n < 5 || m < 5)
            for (int i = 0; i + 2 <= n; i += 2)
                for (int j = 0; j + 2 <= m; j += 2)
                    res.push_back({i, j, 1});
        else {
            int mn = min(n, m);
            if (mn % 4 == 3)
                mn -= 2;
            while (m > mn) {
                for (int i = 0; i + 2 <= n; i += 2)
                    res.push_back({i, m - 2, 1});
                m -= 2;
            }
            while (n > mn) {
                for (int j = 0; j + 2 <= m; j += 2)
                    res.push_back({n - 2, j, 1});
                n -= 2;
            }
            Solve(0, mn, res);
        }
        cout << res.size() << "\n";
        for (auto & re : res)
            cout << re[0] + 1 << " " << re[1] + 1 << " " << re[2] << "\n";
    }
    return 0;
}
