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
        if (a[0] == -1 || a[n - 1] == -1) {
            if (a[0] != -1)
                a[n - 1] = a[0];
            else if (a[n - 1] != -1)
                a[0] = a[n - 1];
        }
        for (auto& x : a)
            if (x == -1)
                x = 0;
        cout << abs(a.back() - a[0]) << "\n";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
