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
        int mn = -1, mx, cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') {
                if (mn == -1)
                    mn = i;
                mx = i;
                cnt++;
            }
        if (cnt >= 3)
            cout << mx - mn << "\n";
        else if (cnt == 2)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
