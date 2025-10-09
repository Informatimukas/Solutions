#include <bits/stdc++.h>
using namespace std;

int F(int p, int t) {
    return max(3 * p / 10, p - p / 250 * t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res1 = F(a, c), res2 = F(b, d);
    if (res1 > res2)
        cout << "Misha\n";
    else if (res1 < res2)
        cout << "Vasya\n";
    else cout << "Tie\n";
    return 0;
}