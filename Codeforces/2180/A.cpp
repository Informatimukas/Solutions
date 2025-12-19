#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int l, a, b;
        cin >> l >> a >> b;
        int res = 0;
        for (int i = 0; i < l; i++) {
            int got = (a + i * b) % l;
            res = max(res, got);
        }
        cout << res << "\n";
    }
    return 0;
}
