#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;
constexpr int Maxn = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> pw(Maxn);
    pw[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw[i] = 2 * pw[i - 1] % mod;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> lim(n + 1);
        lim[n] = a[n] * n;
        for (int i = n - 1; i > 0; i--)
            lim[i] = min(lim[i + 1], a[i] * i);
        int cur = 0;
        ll res = 1;
        for (int i = 1; i <= n; i++) {
            cout << "i = " << i << ", lim = " << lim[i] << endl;
            while (cur < lim[i]) {
                int nxt = min(cur / i * i + i, lim[i]);
                cout << "i = " << i << " " << cur << " to " << nxt << endl;
                res = res * (pw[nxt - cur] - 1) % mod;
                cur = nxt;
            }
            if (cur == i * a[i])
                cur += i;
        }
        cout << res << "\n";
    }
    return 0;
}
