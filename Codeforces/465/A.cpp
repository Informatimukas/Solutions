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
    int pnt = 0;
    while (pnt < s.length() && s[pnt] == '1')
        pnt++;
    if (pnt < s.length() && s[pnt] == '0')
        pnt++;
    cout << pnt << "\n";
    return 0;
}
