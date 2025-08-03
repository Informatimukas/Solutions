#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int res = 0;
    for (int i = 1; i < 1 << s.length(); i++) {
        string tmp(s.length(), '0');
        for (int j = 0; j < s.length(); j++)
            if (i & 1 << j)
                tmp[j] = '1';
        res += tmp <= s;
    }
    cout << res << "\n";
    return 0;
}
