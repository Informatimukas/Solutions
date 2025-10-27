#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s.find('H') != string::npos ||
        s.find('Q') != string::npos ||
        s.find('9') != string::npos)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
