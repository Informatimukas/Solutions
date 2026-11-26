#include <bits/stdc++.h>
using namespace std;

void Solve(int a, int b, int n) {
    for (int i = a; i < n; i += a)
        if ((n - 1 - i) % b == 0 && i / a < a && (n - 1 - i) / b < b) {
            cout << "YES\n";
            cout << "2\n";
            cout << i / a << " " << a << "\n";
            cout << (n - 1 - i) / b << " " << b << "\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int p = 2;
    while (p < n && n % p)
        ++p;
    if (p >= n) {
        cout << "NO\n";
        return 0;
    }
    int a = p, b = n / p;
    while (b % p == 0) {
        a *= p;
        b /= p;
    }
    if (b == 1) {
        cout << "NO\n";
        return 0;
    }
    Solve(a, b, n);
    return 0;
}