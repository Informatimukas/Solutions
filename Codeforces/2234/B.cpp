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
        ll n;
        cin >> n;
        if (n == 10) {
            cout << "-1\n";
            continue;
        }
        ll a = n % 12 == 10? 22 : n % 12;
        cout << a << " " << n - a << "\n";
    }
    return 0;
}
