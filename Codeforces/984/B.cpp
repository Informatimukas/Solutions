#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] != '*') {
                int dig = B[i][j] == '.' ? 0 : B[i][j] - '0';
                int cnt = 0;
                for (int ni = i - 1; ni <= i + 1; ni++)
                    for (int nj = j - 1; nj <= j + 1; nj++)
                        if (0 <= ni && ni < n && 0 <= nj && nj < m)
                            cnt += B[ni][nj] == '*';
                if (cnt != dig) {
                    cout << "NO\n";
                    return 0;
                }
            }
    cout << "YES\n";
    return 0;
}
