#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int res = 0, dif = abs(a - b);
    for (int i = 1; dif; i++) {
        res += i;
        dif--;
        if (dif) {
            res += i;
            dif--;
        }
    }
    cout << res << "\n";
    return 0;
}
