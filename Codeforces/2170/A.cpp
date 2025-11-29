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
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (n == 2) {
            cout << "9\n";
            continue;
        }
        int res = n * n + n * n - 1 + n * n - 2 + n * (n - 1) - 1;
        if (n <= 4) {
            cout << res << "\n";
            continue;
        }
        res = n * (n - 1) - 2 + n * (n - 1) - 1 + n * (n - 1) + n * n - 1 + n * (n - 2) - 1;
        cout << res << "\n";
    }
    return 0;
}
