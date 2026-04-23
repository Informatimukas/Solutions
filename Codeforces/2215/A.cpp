#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, p, q;
        cin >> n >> k >> p >> q;
        vector<int> a(n + 1);
        vector<ll> sum1(n + 1, 0);
        vector<ll> sum2(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum1[i] = sum1[i - 1] + a[i] % q % p;
            sum2[i] = sum2[i - 1] + a[i] % p;
        }
        vector<ll> L(n + 2, 0), R(n + 2, 0);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            L[i] = L[i - 1] + min(a[i] % q % p, a[i] % p);
            res += a[i] % p;
        }
        for (int i = n; i >= 1; i--)
            R[i] = R[i + 1] + min(a[i] % q % p, a[i] % p);
        for (int i = 1; i + k <= n + 1; i++)
            res = min(res, L[i - 1] +
                min(sum1[i + k - 1] - sum1[i - 1], sum2[i + k - 1] - sum2[i - 1]) +
                R[i + k]);
        cout << res << "\n";
    }
    return 0;
}
