#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < n; j++)
            if (B[i][j] == '.' &&
                B[i - 1][j] == '.' && B[i + 1][j] == '.' &&
                B[i][j - 1] == '.' && B[i][j + 1] == '.')
                B[i][j] = B[i - 1][j] = B[i + 1][j] = B[i][j - 1] = B[i][j + 1] = '#';
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (B[i][j] != '#')
                ok = false;
    cout << (ok ? "YES" : "NO") << "\n";
    return 0;
}
