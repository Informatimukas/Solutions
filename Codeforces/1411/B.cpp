#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isFair(ll x) {
    ll num = x;
    while (num) {
        ll d = num % 10;
        if (d != 0 && x % d)
            return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;
        while (!isFair(x))
            ++x;
        cout << x << "\n";
    }
    return 0;
}
