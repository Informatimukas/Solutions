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
        string s;
        cin >> s;
        vector<int> rig(n + 1);
        rig[n] = 0;
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += s[i] == 'b' ? 1 : -1;
            rig[i] = cur;
        }
        if (rig[0] == 0) {
            cout << "0\n";
            continue;
        }
        map<int, int> M = {{0, 0}};
        int res = n;
        cur = 0;
        for (int i = 0; i < n; i++) {
            if (M.contains(rig[i + 1]))
                res = min(res, i + 1 - M[rig[i + 1]]);
            cur += s[i] == 'a' ? 1 : -1;
            M[cur] = i + 1;
        }
        cout << (res >= n ? -1 : res) << "\n";
    }
    return 0;
}
