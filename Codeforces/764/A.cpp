#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, z;
    cin >> n >> m >> z;
    int lcm = n / __gcd(n, m) * m;
    cout << z / lcm << "\n";
    return 0;
}