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
        vector<int> res(n);
        int lef = 1, rig = n;
        int streak = 0, mx = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0') {
                res[i] = rig--;
                streak = 0;
            } else {
                res[i] = lef++;
                streak++;
                mx = max(mx, streak);
            }
        if (mx >= k) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
