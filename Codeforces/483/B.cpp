#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c1, c2, x, y;
    cin >> c1 >> c2 >> x >> y;
    ll lef = 1, rig = Inf;
    while (lef <= rig) {
        ll mid = (lef + rig) / 2;
        if (mid - mid / (x * y) >= c1 + c2 && mid - mid / x >= c1 && mid - mid / y >= c2)
            rig = mid - 1;
        else lef = mid + 1;
    }
    cout << lef << "\n";
    return 0;
}
