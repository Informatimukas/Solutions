#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, d;
    cin >> w >> h >> d;
    int n;
    cin >> n;
    int a = __gcd(w, n);
    n /= a;
    int b = __gcd(h, n);
    n /= b;
    int c = __gcd(d, n);
    n /= c;
    if (n > 1)
        cout << "-1\n";
    else cout << a - 1 << " " << b - 1 << " " << c - 1 << "\n";
    return 0;
}
