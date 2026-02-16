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
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 0)
                ++cnt0;
            else if (a == 1)
                ++cnt1;
        }
        if (cnt0 == 0)
            cout << "NO\n";
        else if (cnt1 > 0 || cnt0 == 1)
                cout << "YES\n";
            else cout << "NO\n";
    }
    return 0;
}
