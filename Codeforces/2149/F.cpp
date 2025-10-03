#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Check(int h, int d, int x) {
    bool extra = h > 0;
    h += x;
    if (extra) x++;
    if (x == 0)
        return false;
    int k = d / x;
    ll need = static_cast<ll>(k) * (k + 1) / 2 * x;
    need += static_cast<ll>(k + 1) * (d % x);
    return need <= h;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int h, d;
        cin >> h >> d;
        h--;
        int lef = 0, rig = d;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(h, d, mid))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << d + lef << "\n";
    }
    return 0;
}
