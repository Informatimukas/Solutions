#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    if (16 * y == 9 * x)
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
