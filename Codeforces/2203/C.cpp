#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 60;

bool Check(ll s, ll m, ll k) {
    for (int i = Maxb - 1; i >= 0; i--)
        if (m & 1ll << i) {
            ll tk = min(s / (1ll << i), k);
            s -= tk * (1ll << i);
        }
    return s == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll s, m;
        cin >> s >> m;
        int b = 0;
        while (!(m & 1ll << b))
            b++;
        if (s % (1ll << b)) {
            cout << "-1\n";
            continue;
        }
        ll lef = 1, rig = s;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            if (Check(s, m, mid))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
