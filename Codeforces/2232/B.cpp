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
        ll sum = 0;
        ll a;
        cin >> a;
        cout << a;
        sum = a;
        for (int i = 1; i < n; i++) {
            int b;
            cin >> b;
            sum += b;
            a = min(a, sum / (i + 1));
            cout << " " << a;
        }
        cout << "\n";
    }
    return 0;
}
