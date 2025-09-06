#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    ll tot = static_cast<ll>(n) * (n - 1) / 2;
    ll res1 = (tot - m) % 3? tot - 1 : tot;
    vector cnt(n + 1, 0);
    tot = static_cast<ll>(n) * (n - 1) / 2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    int bad = 0;
    for (int i = 1; i <= n; i++)
        if ((n - 1 - cnt[i]) % 2)
            bad++;
    assert(bad % 2 == 0);
    ll res2 = tot - bad / 2;
    cout << min(res1, res2) << "\n";
    return 0;
}
