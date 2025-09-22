#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Twos(ll a) {
    int res = 0;
    while (a % 2 == 0) {
        res++;
        a /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        int atwos = Twos(a), btwos = Twos(b);
        if (atwos + btwos == 0)
            cout << a * b + 1 << "\n";
        else if (atwos + btwos >= 2 && btwos >= 1)
            cout << a * b / 2 + 2 << "\n";
        else cout << "-1\n";
    }
    return 0;
}