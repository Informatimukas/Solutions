#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        res += r - l + 1;
    }
    cout << (k - res % k) % k << "\n";
    return 0;
}
