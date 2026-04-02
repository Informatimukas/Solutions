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
        ll a, b;
        cin >> a >> b;
        if (a >= b)
            cout << "Alice\n";
        else if (a >= 2 && b >= 3 && 3 * a - 2 * b >= 0)
            cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
