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
        vector<int> L(s.length()), R(s.length());
        L[0] = 1;
        for (int i = 1; i < s.length(); i++)
            L[i] = s[i] == s[i - 1] ? 1 + L[i - 1] : 1;
        R[s.length() - 1] = 1;
        for (int i = s.length() - 2; i >= 0; i--)
            R[i] = s[i] == s[i + 1] ? 1 + R[i + 1] : 1;
        vector delt(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int lef = 1, rig = n;
            if (i < n - 1) {
                if (s[i] == 'R')
                    rig -= R[i];
                else lef += R[i];
            }
            if (i > 0) {
                if (s[i - 1] == 'R')
                    lef += L[i - 1];
                else rig -= L[i - 1];
            }
            delt[lef]++;
            delt[rig + 1]--;
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += delt[i];
            cout << cur << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}