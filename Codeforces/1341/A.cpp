#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int lef1 = n * (a - b);
        int rig1 = n * (a + b);
        int lef2 = c - d;
        int rig2 = c + d;
        if (max(lef1, lef2) <= min(rig1, rig2))
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
