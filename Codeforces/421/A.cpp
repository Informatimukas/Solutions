#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector res(n + 1, 1);
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
    }
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        res[x] = 2;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
