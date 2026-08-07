#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, m;
        cin >> n >> k >> m;
        if (k > m) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            int a = i % k < k - 1 ? m + 1 : 2 * m - (k - 1);
            cout << a << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
