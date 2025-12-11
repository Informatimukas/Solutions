#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    int dis = 0;
    while (n--) {
        char typ;
        cin >> typ;
        int d;
        cin >> d;
        if (typ == '+')
            x += d;
        else if (d <= x)
            x -= d;
        else dis++;
    }
    cout << x << " " << dis << "\n";
    return 0;
}
