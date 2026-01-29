#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    int lef = x - y - z, rig = x - y + z;
    if (lef > 0)
        cout << "+\n";
    else if (rig < 0)
        cout << "-\n";
    else if (lef == 0 && rig == 0)
        cout << "0\n";
    else cout << "?\n";
    return 0;
}
