#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int res = 0;
        for (int i = 0; i < 20; i++) {
            int tk = min(n / (1 << i), k);
            res += tk;
            n -= (1 << i) * tk;
        }
        cout << res << "\n";
    }
    return 0;
}
