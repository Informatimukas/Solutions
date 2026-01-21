#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n;
    cin >> s;
    if (s[0] == 'S' && s[n - 1] == 'F')
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
