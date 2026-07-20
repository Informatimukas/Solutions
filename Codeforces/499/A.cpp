#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int cur = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        while (cur + x <= l)
            cur += x;
        res += r + 1 - cur;
        cur = r + 1;
    }
    cout << res << "\n";
    return 0;
}
