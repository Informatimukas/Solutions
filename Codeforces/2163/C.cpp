#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxr = 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        array<vector<int>, Maxr> B;
        vector<vector<ii>> seq(2 * n + 1);
        for (int i = 0; i < Maxr; i++) {
            B[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> B[i][j];
                seq[B[i][j]].emplace_back(i, j);
            }
        }
        int top = 0, bottom = n - 1;
        ll res = 0;
        for (int i = 1, j = 0; i <= 2 * n; i++) {
            while (top - bottom <= 1) {
                j++;
                if (j > 2 * n) break;
                while (top < n && i <= B[0][top] && B[0][top] <= j)
                    top++;
                while (bottom >= 0 && i <= B[1][bottom] && B[1][bottom] <= j)
                    bottom--;
            }
            if (j > 2 * n)
                break;
            res += 2 * n - j + 1;
            for (auto& [row, col] : seq[i])
                if (row == 0) top = min(top, col);
                else bottom = max(bottom, col);
        }
        cout << res << "\n";
    }
    return 0;
}
