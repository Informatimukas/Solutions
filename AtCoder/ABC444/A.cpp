#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s[0] == s[1] && s[0] == s[2])
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
