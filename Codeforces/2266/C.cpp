#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] == '1') {
            int res = 0;
            for (int i = 1; i < n; i++)
                res += s[i] != '1';
            cout << res << "\n";
            continue;
        }
        vector<int> L(n + 2);
        vector<int> R(n + 2);
        for (int i = 1; i <= n; i++)
            L[i] = L[i - 1] + (s[i - 1] == '1');
        int res = n;
        for (int i = n; i >= 1; i--)
            R[i] = R[i + 1] + (s[i - 1] == '0');
        for (int i = 0; i <= n; i++)
            res = min(res, L[i] + R[i + 1]);
        cout << res << "\n";
    }
    return 0;
}
