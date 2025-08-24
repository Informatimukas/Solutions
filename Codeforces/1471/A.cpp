#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        ll sum = 0, mx = 0;
        while (n--) {
            int a;
            cin >> a;
            sum += a;
            mx += (a + x - 1) / x;
        }
        cout << (sum + x - 1) / x << " " << mx << "\n";
    }
    return 0;
}
