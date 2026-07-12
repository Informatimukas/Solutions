#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll C(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++)
        res *= (n + 1 - i);
    for (ll i = 1; i <= k; i++)
        res /= i;
    return res;
}

ll Digs(ll x) {
    ll res = 0;
    while (x) {
        res++;
        x /= 10;
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
        ll n, k;
        cin >> n >> k;
        if (n < 20 && (1 << n) < k) {
            cout << "-1\n";
            continue;
        }
        ll rem = k;
        vector<int> seq;
        for (int i = 0; i <= n && rem > 0; i++) {
            ll tk = min(rem, C(n, i));
            for (int j = 0; j < tk; j++)
                seq.push_back(i);
            rem -= tk;
        }
        ranges::reverse(seq);
        ll res = 0;
        for (int i = 1; i <= k; i++)
            res += Digs(i) * seq[i - 1];
        cout << res << "\n";
    }
    return 0;
}
