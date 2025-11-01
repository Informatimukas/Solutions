#include <bits/stdc++.h>
using namespace std;

// Formula sum(i>=1) : C(n + i - 1, n) * C(m + i - 1, m) / (-1)^i * sum(k >= i): (-1)^k * C(k, i) * (k + 1)
// Next step: find how to efficiently compute sum(k >= i): (-1)^(k-i) * C(k, i)

using ll = long long;

constexpr int mod = 1000000007;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int Maxn = 305;
    vector C(Maxn, vector(Maxn, 0));
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int res = 0;
        int pw2 = mod - 1;
        for (int i = 1; i <= n + m; i++) {
            int mult = static_cast<ll>(C[n + i - 1][n]) * C[m + i - 1][m] % mod;
            mult = static_cast<ll>(mult) * toPower(Inv(pw2), i) % mod;
            int add = 0;
            for (int k = i; k <= n + m; k++) {
                int cur = static_cast<ll>(C[k][i]) * toPower(pw2, k) % mod * (k + 1) % mod;
                add = (add + cur) % mod;
            }
            cout << "add i = " << i << ", add = " << add << endl;
            res = (res + static_cast<ll>(mult) * add) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}