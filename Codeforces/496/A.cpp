#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i)
            res = max(res, a[i] - a[i - 1]);
    }
    int mn = 1000000000;
    for (int i = 1; i + 1 < n; i++)
        mn = min(mn, a[i + 1] - a[i - 1]);
    res = max(res, mn);
    cout << res << "\n";
    return 0;
}
