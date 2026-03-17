#include <bits/stdc++.h>
using namespace std;

int countFinalWays(const string& s) {
    int res = 1;
    if (s[0] == '_')
        res *= 9;
    else if (s[0] == '0')
        return 0;
    for (int i = 1; i < s.length(); i++)
        if (s[i] == '_')
            res *= 10;
    return res;
}

int countWays(string s, char X) {
    for (auto& ch : s)
        if (ch == 'X')
            ch = X;
    if (s.size() == 1)
        return s[0] == '0' || s[0] == '_';
    vector<string> cands = {"00", "25", "50", "75"};
    int res = 0;
    for (auto& ch : cands) {
        string cur = s;
        if ((cur[cur.length() - 2] == '_' || cur[cur.length() - 2] == ch[0]) &&
            (cur[cur.length() - 1] == '_' || cur[cur.length() - 1] == ch[1])) {
            cur[cur.length() - 2] = ch[0];
            cur[cur.length() - 1] = ch[1];
            res += countFinalWays(cur);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    char lef, rig;
    if (s.find('X') != string::npos)
        if (s.length() > 1 && s[0] == 'X') { lef = '1'; rig = '9'; }
        else { lef = '0'; rig = '9'; }
    else lef = rig = '0';
    int res = 0;
    for (char ch = lef; ch <= rig; ch++)
        res += countWays(s, ch);
    cout << res << "\n";
    return 0;
}