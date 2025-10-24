#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector rows(n, 0), cols(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            rows[i] += a;
            cols[j] += a;
        }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res += cols[j] > rows[i];
    cout << res << endl;
    return 0;
}
