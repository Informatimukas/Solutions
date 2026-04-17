#include <bits/stdc++.h>
using namespace std;

bool Check(int n, int m, int a, int b) {
    return __gcd(n, a) == 1 && __gcd(m, b) == 1 && __gcd(n, m) <= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << (Check(n, m, a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}