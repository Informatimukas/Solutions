#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        res += s[i] == s[i + 1];
    cout << res << "\n";
    return 0;
}
