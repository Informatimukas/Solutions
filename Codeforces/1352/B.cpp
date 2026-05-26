#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k % 2 == n % 2 && k <= n) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << "1 ";
            cout << n - (k - 1) << "\n";
            continue;
        }
        if (n % 2 == 0 && 2 * k <= n) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << "2 ";
            cout << n - 2 * (k - 1) << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
