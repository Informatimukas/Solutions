#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    int res = 0;
    while (n) {
        if (n % 10 == 4 || n % 10 == 7)
            res++;
        n /= 10;
    }
    if (res == 4 || res == 7)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
