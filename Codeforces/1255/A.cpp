#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int dif = abs(a - b);
        int res = dif / 5 + dif % 5 / 2 + dif % 5 % 2;
        cout << res << "\n";
    }
    return 0;
}
