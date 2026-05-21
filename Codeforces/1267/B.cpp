#include <bits/stdc++.h>
using namespace std;

int Solve(string_view s) {
    if (s[0] != s[s.length() - 1])
        return 0;
    int lef = 0;
    while (lef < s.length() && s[0] == s[lef])
        lef++;
    if (lef >= s.length())
        return s.length() >= 2 ? s.length() + 1 : 0;
    int rig = s.length() - 1;
    while (s[rig] == s[s.length() - 1])
        rig--;
    string_view nw = s.substr(lef, rig - lef + 1);
    if (s.length() - nw.length() < 3)
        return 0;
    return Solve(nw);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << Solve(s) << "\n";
    return 0;
}
