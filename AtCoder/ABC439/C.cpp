#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector cnt(n + 1, 0);
    for (int y = 2; y * y <= n; y++)
        for (int x = 1; x < y && x * x + y * y <= n; x++) {
            int got = x * x + y * y;
            cnt[got]++;
        }
    int tot = 0;
    for (auto& x : cnt)
        if (x == 1)
            ++tot;
    cout << tot << "\n";
    if (!tot)
        cout << "\n";
    for (int i = 0; i <= n; i++)
        if (cnt[i] == 1)
            cout << i << (--tot ? ' ' : '\n');
    return 0;
}
