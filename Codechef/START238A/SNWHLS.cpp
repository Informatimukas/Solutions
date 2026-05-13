#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 30;

int Count(int a, int b) {
    int lvl = Maxb;
    while (lvl >= 0 && (a & 1 << lvl) == (b & 1 << lvl))
        lvl--;
    int need = 0;
    bool has = false;
    for (int i = 0; i <= lvl; i++) {
        if (b & 1 << i)
            need++;
        if (a & 1 << i)
            has = true;
    }
    return need - static_cast<int>(has);
}

ll Solve(int a, int b, ll k, ll h) {
    ll res = Count(a, b) * h;
    int targ = b;
    for (int i = 0; i <= Maxb; i++)
        if (b & 1 << i)
            targ ^= 1 << i;
        else {
            int cand = targ | 1 << i;
            res = min(res, Count(a, cand) * h + (cand - b) * k);
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
        ll n, k, h;
        cin >> n >> k >> h;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ll res = 0;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] >= a[i + 1])
                res += (a[i] - a[i + 1]) * k;
            else {
                ll add = Solve(a[i], a[i + 1], k, h);
                if (a[i] > 1)
                    add = min(add, Solve(a[i] - 1, a[i + 1], k, h) + k);
                res += add;
            }
        cout << res << "\n";
    }
    return 0;
}
