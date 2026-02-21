#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = n - 1; i > 0; i--)
        if (i < n - i && __gcd(i, n - i) == 1) {
            cout << i << " " << n - i << "\n";
            break;
        }
    return 0;
}
