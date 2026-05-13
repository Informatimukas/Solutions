#include <bits/stdc++.h>
using namespace std;

void Switch(char& ch) {
    if (ch == '0')
        ch = '1';
    else ch = '0';
}

int Count(string s, int pos) {
    int rig = s.length() - 1;
    while (rig >= 0 && s[rig] != '1')
        rig--;
    if (rig < 0)
        return 0;
    int res = 0;
    while (pos + 1 < rig)
        if (s[pos] == '0') {
            Switch(s[pos + 1]);
            res++;
            pos++;
        } else {
            res += 3;
            pos++;
        }
    if (pos + 1 == rig) {
        if (s[pos] == '0')
            res++;
        else res += 2;
    } else res += 3;
    return res;
}

int Solve(string s, int pos) {
    int lef = 0, rig = s.length() - 1;
    while (lef < s.length() && s[lef] != '1')
        lef++;
    if (lef >= s.length())
        return 0;
    while (s[rig] != '1')
        rig--;
    Switch(s[pos]);
    // res1
    int res1 = 1;
    string tmp = s;
    for (int i = lef; i < pos; i++) {
        Switch(tmp[i]);
        res1++;
    }
    res1 += Count(tmp, min(pos, lef));
    // res2
    int res2 = 1;
    tmp = s;
    for (int i = pos + 1; i <= rig; i++) {
        Switch(tmp[i]);
        res2++;
    }
    ranges::reverse(tmp);
    pos = s.length() - 1 - max(rig, pos);
    res2 += Count(tmp, pos);
    return min(res1, res2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, pos;
        cin >> n >> pos;
        string s;
        cin >> s;
        cout << Solve(s, pos - 1) << "\n";
    }
    return 0;
}
