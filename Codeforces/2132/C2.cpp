#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxa = 21;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        array<int, Maxa> cnt{};
        array<ll, Maxa> pw3{};
        pw3[0] = 1;
        for (int i = 1; i < Maxa; i++)
            pw3[i] = 3ll * pw3[i - 1];
        int tot = 0;
        while (n > 0) {
            ll val = 1;
            int x = 0;
            while (val * 3 <= n) {
                val *= 3;
                x++;
            }
            cnt[x]++;
            tot++;
            n -= val;
        }
        if (tot > k) {
            cout << "-1\n";
            continue;
        }
        int lft = (k - tot) / 2;
        for (int i = Maxa - 1; i > 0; i--) {
            int tk = min(cnt[i], lft);
            cnt[i] -= tk;
            lft -= tk;
            cnt[i - 1] += 3 * tk;
        }
        ll res = 0;
        for (int i = 0; i < Maxa; i++)
            res += cnt[i] * (pw3[i + 1] + i * pw3[i - 1]);
        cout << res << "\n";
    }
    return 0;
}
