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
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < i; j++)
                res = max(res, a[i] ^ a[j]);
        }
        cout << res << "\n";
    }
    return 0;
}
