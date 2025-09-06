#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<string> B(n);
    vector sum(n - 1, vector(n - 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++) {
            if (B[i][j] == '.' && B[i + 1][j] == '.' &&
                B[i][j + 1] == '.' && B[i + 1][j + 1] == '.')
                sum[i][j] = 1;
            if (i) sum[i][j] += sum[i - 1][j];
            if (j) sum[i][j] += sum[i][j - 1];
            if (i && j) sum[i][j] -= sum[i - 1][j - 1];
        }
    while (q--) {
        int r1, r2, c1, c2;
        cin >> r1 >> r2 >> c1 >> c2;
        r1--; c1--;
        r2 -= 2; c2 -= 2;
        int res = sum[r2][c2];
        if (r1) res -= sum[r1 - 1][c2];
        if (c1) res -= sum[r2][c1 - 1];
        if (r1 && c1) res += sum[r1 - 1][c1 - 1];
        cout << res << "\n";
    }
    return 0;
}
