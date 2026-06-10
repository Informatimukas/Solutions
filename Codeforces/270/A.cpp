#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a;
        cin >> a;
        bool ok = false;
        for (int i = 3; i <= 100000; i++)
            if (a * i == (i - 2) * 180) {
                ok = true;
                break;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
