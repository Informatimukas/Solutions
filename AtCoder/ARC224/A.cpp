#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Check(ll x) {
    auto str = to_string(x);
    return str.find("00") != string::npos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll k;
        cin >> k;
        for (ll i = 1; i <= 100; i++)
            if (Check(k * i)) {
                cout << k * i << "\n";
                break;
            }
    }
    return 0;
}
