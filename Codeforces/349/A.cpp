#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int c25 = 0, c50 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 25)
            c25++;
        else if (a == 50) {
            if (c25 == 0) {
                cout << "NO\n";
                return 0;
            }
            c25--;
            c50++;
        } else {
            int rem = 75;
            if (c50 > 0) {
                rem -= 50;
                c50--;
            }
            if (c25 < rem / 25) {
                cout << "NO\n";
                return 0;
            }
            c25 -= rem / 25;
        }
    }
    cout << "YES\n";
    return 0;
}
