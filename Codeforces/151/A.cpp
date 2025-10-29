#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = k * l / nl;
    int lime = c * d;
    int salt = p / np;
    cout << min({drink, lime, salt}) / n << endl;
    return 0;
}