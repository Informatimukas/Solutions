#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    int x2, y2;
    cin >> x2 >> y2;
    if (x <= x2 && x2 <= x + 99 && y <= y2 && y2 <= y + 99)
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
