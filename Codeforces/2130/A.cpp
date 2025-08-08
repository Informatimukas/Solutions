#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        while (n--) {
            int x;
            cin >> x;
            res += max(x, 1);
        }
        cout << res << "\n";
    }
    return 0;
}
