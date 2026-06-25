#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    for (auto a = l; a <= r; a++)
        for (auto b = a + 1; b <= r; b++)
            for (auto c = b + 1; c <= r; c++)
                if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) != 1) {
                    cout << a << " " << b << " " << c << "\n";
                    return 0;
                }
    cout << "-1\n";
    return 0;
}
