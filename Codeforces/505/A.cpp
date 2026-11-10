#include <bits/stdc++.h>
using namespace std;

bool Solve(string& s) {
    int l = 0, r = s.length() - 1;
    while (l <= r) {
        if (s[l] == '?')
            s[l] = s[r] == '?' ? 'a' : s[r];
        else if (s[r] == '?')
            s[r] = s[l] == '?' ? 'a' : s[l];
        else if (s[l] != s[r])
            return false;
        ++l;
        --r;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i <= s.length(); i++) {
        string res = s;
        res.insert(res.begin() + i, '?');
        if (Solve(res)) {
            cout << res << "\n";
            return 0;
        }
    }
    cout << "NA\n";
    return 0;
}
