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
    if (ranges::count(s, '0') * 2 == n)
        cout << "2\n" << s[0] << " " << s.substr(1) << "\n";
    else cout << "1\n" << s << "\n";
    return 0;
}
