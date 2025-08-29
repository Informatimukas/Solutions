#include <bits/stdc++.h>
using namespace std;

bool Check(int n, int d) {
    if (n % d == 0)
        return true;
    for (int i = 1; i < 10; i++) {
        int g = 10 * i + d;
        if (g <= n && (n - g) % d == 0)
            return true;
    }
    for (int i = 1; i < 10; i++) {
        int g = d * 10 + i;
        if (g <= n && (n - g) % d == 0)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int q, d;
        cin >> q >> d;
        while (q--) {
            int a;
            cin >> a;
            cout << (Check(a, d) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
