#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxval = 200005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, y;
        cin >> n >> y;
        vector cnt(Maxval, 0);
        vector sum(Maxval, 0);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            cnt[c]++;
        }
        for (int i = 1; i < Maxval; i++)
            sum[i] = sum[i - 1] + cnt[i];
        ll res = -static_cast<ll>(n) * y;
        for (int i = 2; i < Maxval; i++) {
            ll cand = 0;
            int lst = 0;
            for (int j = i; j < Maxval; j += i) {
                int got = sum[j] - sum[lst];
                if (got > cnt[j / i])
                    cand -= static_cast<ll>(got - cnt[j / i]) * y;
                cand += static_cast<ll>(got) * (j / i);
                lst = j;
            }
            int got = sum[Maxval - 1] - sum[lst];
            if (got > cnt[lst / i + 1])
                cand -= static_cast<ll>(got - cnt[lst / i + 1]) * y;
            cand += static_cast<ll>(got) * (lst / i + 1);
            res = max(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
