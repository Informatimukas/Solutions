#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            res += a == 1 || b == 1;
        }
    cout << res << "\n";
    return 0;
}
