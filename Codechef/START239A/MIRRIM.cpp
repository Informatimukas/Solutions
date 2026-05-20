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
        ranges::sort(a);
        int x = a[0] + a[n - 1];
        bool ok = true;
        for (int i = 0; i < n / 2; i++)
            if (a[i] + a[n - 1 - i] != x) {
                ok = false;
                break;
            }
        int x1 = x / 2;
        int x2 = x - x1;
        if (x1 == x2) {
            x1--;
            x2++;
        }
        if (a[n / 2 - 1] > x1 || a[n / 2] < x2)
            ok = false;
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
