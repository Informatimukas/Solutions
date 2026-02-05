#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, s, x;
        cin >> n >> s >> x;
        while (n--) {
            int a;
            cin >> a;
            s -= a;
        }
        if (s >= 0 && s % x == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
