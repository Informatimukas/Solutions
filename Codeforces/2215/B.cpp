#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 100;

int Get(ll n, ll b, const array<array<int, Maxm>, Maxm>& G) {
    int lst = -1, cur = 0, res = 0;
    while (n) {
        int got = n % b;
        n /= b;
        if (lst != got) {
            res = G[res][cur];
            cur = 0;
            lst = got;
        }
        cur++;
    }
    return G[res][cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        array<array<int, Maxm>, Maxm> G{};
        for (int i = 0; i < Maxm; i++)
            for (int j = 0; j < Maxm; j++)
                G[i][j] = __gcd(i, j);
        array<int, Maxm> cnt{};
        for (ll b = 2; b * b <= n; b++)
            cnt[Get(n, b, G)]++;
        for (ll i = 1; i * i <= n; i++)
            if (n % i == 0) {
                ll b = n / i - 1;
                if (b > 1000000 || n < b * b)
                    cnt[Get(n, b, G)]++;
            }
        int res = 0;
        for (int i = 2; i < Maxm; i++) {
            int tims = 0;
            for (int j = 2; j <= i; j++)
                if (i % j == 0)
                    tims++;
            res += tims * cnt[i];
        }
        cout << res << "\n";
    }
    return 0;
}
