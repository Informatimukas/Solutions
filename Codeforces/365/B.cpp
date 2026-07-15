#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int my = 1;
        if (i >= 1)
            my = 2;
        if (i >= 2 && a[i] == a[i - 1] + a[i - 2])
            my = cur + 1;
        cur = my;
        res = max(res, cur);
    }
    cout << res << "\n";
    return 0;
}
