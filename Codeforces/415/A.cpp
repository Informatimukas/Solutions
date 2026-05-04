#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> res(n + 1);
    int cur = n;
    while (m--) {
        int b;
        cin >> b;
        while (cur >= b)
            res[cur--] = b;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
