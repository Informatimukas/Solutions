#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int s, k, m;
        cin >> s >> k >> m;
        int res;
        if (s <= k || m / k % 2 == 0)
            res = max(0, s - m % k);
        else res = max(0, k - m % k);
        cout << res << "\n";
    }
    return 0;
}