#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Solve(int n, int m) {
    if (m == 1) {
        cout << "1 2\n";
        return;
    }
    for (int i = 1; i < 30; i++)
        for (int j = 1; j <= n - 1; j++) {
            ll cur = ((1ll << i) - 1ll) * j;
            ll x = m - cur;
            ll y = x + j;
            if (1 <= x && x < y && y <= n) {
                cout << x << " " << y << "\n";
                return;
            }
        }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        Solve(n, m);
    }
    return 0;
}
