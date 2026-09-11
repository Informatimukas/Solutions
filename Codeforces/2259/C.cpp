#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int pnt = 0;
        while (pnt < n && a[pnt] == 0)
            pnt++;
        if (pnt < n)
            a[pnt] = 1;
        pnt = n - 1;
        while (pnt >= 0 && a[pnt] == 0)
            pnt--;
        if (pnt >= 0)
            a[pnt] = 1;
        for (auto& x : a)
            if (x == -1)
                x = 0;
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
