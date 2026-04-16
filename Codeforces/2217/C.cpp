#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << n % a << " " << m % b << endl;
        if (__gcd(n, a) == 1 && __gcd(m, b) == 1 && __gcd(n + m - 1, a + b) == 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
