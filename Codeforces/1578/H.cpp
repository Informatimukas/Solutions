#include <bits/stdc++.h>
using namespace std;

int Get(string_view s) {
    if (s.empty())
        return 0;
    int st = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-' && st == 0)
            return max(Get(s.substr(0, i)) + 1, Get(s.substr(i + 2)));
        if (s[i] == '(')
            st++;
        else if (s[i] == ')')
            st--;
    }
    return Get(s.substr(1, s.length() - 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << Get(s) << "\n";
    return 0;
}