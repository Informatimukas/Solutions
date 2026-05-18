#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> rig(s.length() + 1);
        for (int i = s.length() - 1; i >= 0; i--)
            rig[i] = rig[i + 1] + (s[i] == '1' || s[i] == '3');
        int res = rig[0];
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            cur += s[i] == '2';
            res = max(res, cur + rig[i + 1]);
        }
        cout << s.length() - res << "\n";
    }
    return 0;
}
