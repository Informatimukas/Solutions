#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ind = s.find('^');
    ll res = 0;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]))
            res += (i - ind) * (s[i] - '0');
    if (res > 0)
        cout << "right\n";
    else if (res < 0)
        cout << "left\n";
    else cout << "balance\n";
    return 0;
}
