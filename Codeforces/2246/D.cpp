#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = (1 << 25) + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> val(Maxn);
    for (int i = 1; i < Maxn; i++)
        val[i] = 1 + (i % 2 ? val[i - 1] : val[i / 2]);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        ll res = 1000000000;
        for (int b = 0; b <= 20; b++) {
            ll cand = b;
            for (auto x : a) {
                ll nw = (x + (1 << b) - 1) / (1 << b) * (1 << b);
                ll best = nw - x + val[nw / (1 << b)];
                for (int j = 1; j <= 30; j++)
                    best = min(best, nw + j * (1 << b) - x + val[nw / (1 << b) + j]);
                cand += best;
            }
            res = min(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
