#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ll res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'C')
            res += min(i + 1, static_cast<int>(s.length()) - i);
    cout << res << "\n";
    return 0;
}
