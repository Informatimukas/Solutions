#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (mx > a)
                mx += a;
            else mx = a;
        }
        cout << mx << "\n";
    }
    return 0;
}
