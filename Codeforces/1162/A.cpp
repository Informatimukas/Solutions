#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m;
    cin >> n >> h >> m;
    vector mx(n + 1, h);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; i++)
            mx[i] = min(mx[i], x);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += mx[i] * mx[i];
    cout << res << "\n";
    return 0;
}
