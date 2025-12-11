#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool bad = s[0] != '1';
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '1' && s[i] != '4')
            bad = true;
    for (int i = 0; i + 3 <= s.length(); i++)
        if (s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '4')
            bad = true;
    cout << (bad ? "NO" : "YES") << "\n";
    return 0;
}