#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        int n, m;
        cin >> n >> m;
        int rem = n - m;
        if (0 <= rem && rem <= m - 2) {
            cout << "YES\n";
            continue;
        }
        int x = (n + 2) / 2;
        if (n % 2 == 0 && x > m)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
