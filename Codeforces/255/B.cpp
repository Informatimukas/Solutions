#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto& c : s)
        if (c == 'x')
            x++;
        else y++;
    int tk = min(x, y);
    x -= tk;
    y -= tk;
    if (x)
        cout << string(x, 'x') << "\n";
    else cout << string(y, 'y') << "\n";
    return 0;
}
