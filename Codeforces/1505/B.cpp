#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    while (a >= 10) {
        int res = 0;
        while (a) {
            res += a % 10;
            a /= 10;
        }
        a = res;
    }
    cout << a << "\n";
    return 0;
}
