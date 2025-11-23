#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> L(s.length()), R(s.length());
    for (int i = 0; i < s.length(); i++) {
        L[i] = 1;
        if (i > 0 && s[i - 1] == s[i])
            L[i] += L[i - 1];
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        R[i] = 1;
        if (i + 1 < s.length() && s[i] == s[i + 1])
            R[i] += R[i + 1];
    }
    int res = 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i - 1] + 1 == s[i])
            res += min(L[i - 1], R[i]);
    cout << res << "\n";
    return 0;
}