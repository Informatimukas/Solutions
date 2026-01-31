#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr int Maxb = 50;

ll simpleSolve(ll siz) {
    ll res = 1;
    while (siz % 2 == 0) {
        siz /= 2;
        res *= 2;
    }
    return res;
}

ll Solve(int b, ll lef, ll rig) {
    if (b < 0)
        return 1;
    if (!(rig & 1ll << b))
        return Solve(b - 1, lef, rig);
    if (lef & 1ll << b)
        return Solve(b - 1, lef - (1ll << b), rig - (1ll << b));
    ll cnt1 = (1ll << b) - lef;
    ll cnt2 = rig - (1ll << b) + 1;
    if (cnt1 == cnt2)
        return 2 * simpleSolve(cnt1);
    return min(simpleSolve(cnt1), simpleSolve(cnt2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll lef, rig;
        cin >> lef >> rig;
        cout << Solve(Maxb - 1, lef, rig) - 1 << "\n";
    }
    return 0;
}
