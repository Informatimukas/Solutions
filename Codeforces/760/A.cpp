#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, d;
    cin >> m >> d;
    int days;
    if (m == 2)
        days = 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        days = 30;
    else days = 31;
    int res = 1;
    days--;
    while (days--)
        if (++d > 7) {
            d = 1;
            res++;
        }
    cout << res << "\n";
    return 0;
}
