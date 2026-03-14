#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string res(s.length(), '?');
    int lef = 0, rig = s.length() - 1;
    for (int i = res.length() - 1; i >= 0; i--)
        res[i] = i % 2 ? s[rig--] : s[lef++];
    cout << res << "\n";
    return 0;
}
