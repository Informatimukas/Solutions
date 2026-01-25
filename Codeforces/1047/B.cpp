#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        res = max(res, x + y);
    }
    cout << res << "\n";
    return 0;
}
