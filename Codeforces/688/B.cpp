#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string r = s;
    ranges::reverse(r);
    s += r;
    cout << s << "\n";
    return 0;
}
