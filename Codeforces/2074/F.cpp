#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxk = 21;

ll Solve(int l1, int r1, int l2, int r2) {
    array<ll, Maxk> a{};
    for (int i = 0; i < Maxk; i++) {
        int s = 1 << i;
        int L1 = (l1 + s - 1) / s * s;
        int R1 = r1 / s * s;
        int L2 = (l2 + s - 1) / s * s;
        int R2 = r2 / s * s;
        if (L1 <= R1 && L2 <= R2)
            a[i] = static_cast<ll>((R1 - L1) / s) * ((R2 - L2) / s);
    }
    ll res = 0;
    for (int i = 0; i < Maxk; i++) {
        if (i + 1 < Maxk)
            a[i] -= 4 * a[i + 1];
        res += a[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << Solve(l1, r1, l2, r2) << "\n";
    }
    return 0;
}
