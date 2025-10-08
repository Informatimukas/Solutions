#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int lef = 0;
        while (lef < n && s[lef] == '0')
            lef++;
        if (lef >= n) {
            cout << "0\n";
            continue;
        }
        int rig = n - 1;
        while (rig >= 0 && s[rig] == '0')
            rig--;
        int res = 0;
        for (int i = lef; i <= rig; i++)
            res += s[i] == '0';
        cout << res << "\n";
    }
    return 0;
}