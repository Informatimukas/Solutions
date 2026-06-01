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
        ll x, y;
        cin >> x >> y;
        cout << (x + x < y ? "YES" : "NO") << "\n";
    }
    return 0;
}
