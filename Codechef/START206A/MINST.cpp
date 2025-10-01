#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 4000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, d;
        cin >> n >> d;
        ll res = Inf;
        for (int i = 0; i < 62; i++)
            if (1ll << i <= n && (n - (1ll << i)) % d == 0) {
                ll cand = i;
                ll rem = (n - (1ll << i)) / d;
                cand += __builtin_popcountll(rem & ((1ll << i) - 1ll));
                cand += rem / (1ll << i);
                res = min(res, cand);
            }
        if (res >= Inf)
            res = -1;
        cout << res << "\n";
    }
    return 0;
}
