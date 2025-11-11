#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

bool Solve(vector<string>& B) {
    int n = B.size();
    vector bad(n, vector(n, false));
    int tot = 0;
    bool square = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            tot += B[i][j] == '#';
            if (i + 3 <= n) {
                int cnt = 0;
                for (int i2 = 0; i2 < 3; i2++)
                    cnt += B[i + i2][j] == '#';
                if (cnt == 3)
                    return false;
            }
            if (j + 3 <= n) {
                int cnt = 0;
                for (int j2 = 0; j2 < 3; j2++)
                    cnt += B[i][j + j2] == '#';
                if (cnt == 3)
                    return false;
            }
            if (i + 2 <= n && j + 2 <= n &&
                B[i][j] == '#' && B[i][j + 1] == '#' &&
                B[i + 1][j] == '#' && B[i + 1][j + 1] == '#')
                square = true;
        }
    if (tot == 4 && square == true)
        return true;
    int mn1 = Inf, mx1 = -Inf;
    int mn2 = Inf, mx2 = -Inf;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++)
            if (B[i][j] == '#') {
                mn1 = min(mn1, i - j);
                mx1 = max(mx1, i - j);
                mn2 = min(mn2, i + j);
                mx2 = max(mx2, i + j);
            }
    }
    return mx1 - mn1 <= 1 || mx2 - mn2 <= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        cout << (Solve(B) ? "YES" : "NO") << "\n";
    }
    return 0;
}