#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    do {
        int d = n % 10;
        n /= 10;
        string a = "--";
        string b = "OOOOO";
        a[d >= 5] = 'O';
        b[d % 5] = '-';
        cout << a << "|" << b << "\n";
    } while (n);
    return 0;
}
