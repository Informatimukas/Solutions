#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Read() {
    int n;
    ll bas;
    cin >> n >> bas;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        res = res * bas + a;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a = Read();
    ll b = Read();
    if (a < b)
        cout << "<";
    else if (a > b)
        cout << ">";
    else cout << "=";
    cout << "\n";
    return 0;
}
