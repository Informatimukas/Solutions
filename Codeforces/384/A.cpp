#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector res(n, string(n, '.'));
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2 == 0) {
                res[i][j] = 'C';
                ++cnt;
            }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i] << "\n";
    return 0;
}
