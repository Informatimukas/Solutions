#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0 0 0\n";
        return 0;
    }
    int a = 0, b = 1;
    while (a + b < n) {
        int c = a + b;
        a = b;
        b = c;
    }
    cout << a << " " << b << " 0\n";
    return 0;
}
