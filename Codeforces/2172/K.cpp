#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 1000006;

void Solve(const vector<string>& B, int r, int c, int dr, int dc, int add, int mult, int cur,
    vector<int>& cnt) {
    int n = B.size();
    int m = B[0].length();
    if (r < 0 || r >= n || c < 0 || c >= m || !isdigit(B[r][c]) && cur == 0)
        return;
    if (isdigit(B[r][c])) {
        cur = 10 * cur + (B[r][c] - '0');
        const int got = add + mult * cur;
        if (got < Maxl) {
            cnt[got]++;
            Solve(B, r + dr, c + dc, dr, dc, add, mult, cur, cnt);
        }
        return;
    }
    if (B[r][c] == '+') {
        add += mult * cur;
        mult = 1;
        cur = 0;
    } else {
        mult *= cur;
        cur = 0;
    }
    Solve(B, r + dr, c + dc, dr, dc, add, mult, cur, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    vector cnt(Maxl, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isdigit(B[i][j])) {
                int cur = B[i][j] - '0';
                cnt[cur]++;
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++)
                        if (di || dj)
                            Solve(B, i + di, j + dj, di, dj, 0, 1, cur, cnt);
            }
    while (q--) {
        int a;
        cin >> a;
        cout << cnt[a] << "\n";
    }
    return 0;
}
