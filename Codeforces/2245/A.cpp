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
        string s;
        cin >> s;
        if (n < 2 * k) {
            cout << "-1\n";
            continue;
        }
        int res = 0;
        for (int i = 0; i < k; i++) {
            res += s[i] != 'R';
            res += s[n - 1 - i] != 'L';
        }
        cout << res << "\n";
    }
    return 0;
}
