#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll step = 1000000000;
constexpr ll Inf = 1000000000000000000ll;

ll Move(int tims, char dir, int x) {
    ll res;
    while (tims--) {
        cout << "? " << dir << " " << x << endl;
        cin >> res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll m1 = Inf, m2 = Inf;
        while (n--) {
            ll x, y;
            cin >> x >> y;
            m1 = min(m1, x + y);
            m2 = min(m2, y - x);
        }
        Move(2, 'L', step);
        ll v1 = Move(2, 'D', step);
        ll v2 = Move(4, 'R', step);
        ll x = (m1 - m2 - v1 + v2) / 2;
        ll y = m1 - x + 4 * step - v1;
        cout << "! " << x << " " << y << endl;
    }
    return 0;
}