#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s[0] == s[s.length() - 1])
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
