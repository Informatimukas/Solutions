#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string t;
    cin >> s >> t;
    int pnt = 0;
    for (auto& ch : t)
        if (s[pnt] == ch)
            pnt++;
    cout << pnt + 1 << "\n";
    return 0;
}
