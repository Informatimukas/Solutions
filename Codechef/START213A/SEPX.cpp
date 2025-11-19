#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        int small = 0, eq = 0, big = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a < x)
                small++;
            else if (a == x)
                eq++;
            else big++;
        }
        if (eq > 0 || small == n || big == n)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
