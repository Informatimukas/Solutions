#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        for (int i = 1; i <= n; i++) {
            int cur = i == r ? l - 1 : i;
            int prv = i - 1 == r ? l - 1 : i - 1;
            cout << (cur ^ prv) << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
