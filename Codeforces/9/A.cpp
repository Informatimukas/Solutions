#include <bits/stdc++.h>
using namespace std;

int Gcd(int x, int y) { return x? Gcd(y % x, x): y; }

int a, b;

int main()
{
    cin >> a >> b;
    int res1 = 7 - max(a, b);
    int res2 = 6;
    int g = Gcd(res1, res2);
    cout << res1 / g << "/" << res2 / g << "\n";
    return 0;
}
