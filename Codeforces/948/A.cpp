#include <bits/stdc++.h>
using namespace std;

bool Bad(char a, char b) {
    return a == 'S' && b == 'W' || a == 'W' && b == 'S';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& s : B)
        cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && Bad(B[i][j], B[i + 1][j])) {
                cout << "No\n";
                return 0;
            }
            if (j + 1 < m && Bad(B[i][j], B[i][j + 1])) {
                cout << "No\n";
                return 0;
            }
            if (B[i][j] == '.')
                B[i][j] = 'D';
        }
    cout << "Yes\n";
    for (auto& x : B)
        cout << x << "\n";
    return 0;
}
