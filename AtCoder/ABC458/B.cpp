#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int res = (i > 0) + (i + 1 < n) + (j > 0) + (j + 1 < m);
            cout << res << (j + 1 < m ? ' ' : '\n');
        }
    return 0;
}
