#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int tmp;
        for (int i = 0; i < n; i++)
            cin >> tmp;
        for (int i = 0; i < m; i++)
            cin >> tmp;
        cout << n + m << "\n";
    }
    return 0;
}
