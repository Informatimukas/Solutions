#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > 1)
            a[x - 1] += y - 1;
        if (x < n)
            a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\n";
    return 0;
}
