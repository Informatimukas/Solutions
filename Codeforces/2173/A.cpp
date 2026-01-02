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
        int nxt = 0, res = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') {
                res += max(0, i - nxt);
                nxt = i + k + 1;
            }
        res += max(0, n - nxt);
        cout << res << "\n";
    }
    return 0;
}
