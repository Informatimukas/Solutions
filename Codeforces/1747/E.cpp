#include <bits/stdc++.h>
using namespace std;

// Formula sum(i>=1) : C(n + i - 1, n) * C(m + i - 1, m) / (-1)^i * sum(k >= i): (-1)^k * C(k, i) * (k + 1)
// Next step: find how to efficiently compute sum(k >= i): (-1)^(k-i) * C(k, i)
// I transformed sum(k >= i): (-1)^k * C(k, i) * (k + 1) to
// sum(d in 0..n+m-i): C(d+i+1, d)*(-1)^d ((-1)^i earlier disappears). It should be more
// manageable. It is related to expansion of (1+x)^(-(i+2)).

using ll = long long;
using ld = long double;

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
        vector<int> multSum(n + m + 1);
        multSum[n + m] = 1;
        for (int i = n + m - 1; i > 0; i--)
            multSum[i] = (static_cast<ll>(mod - (i + 2)) * multSum[i + 1] + 1) % mod;
        for (int i = 1; i <= n + m; i++)
            cout << "multSum[" << i << "] = " << multSum[i] << endl;
        int res = 0;
        for (int i = 1; i <= n + m; i++) {
            int mult = static_cast<ll>(C[n + i - 1][n]) * C[m + i - 1][m] % mod;
            cout << "i = " << i << endl;
            cout << "new = " << static_cast<ll>(i + 1) * multSum[i] % mod << endl;
            int old = 0;
            for (int k = i; k <= n + m; k++) {
                int ways = static_cast<ll>(C[k][i]) * (k + 1);
                if ((k + i) % 2)
                    ways = (mod - ways) % mod;
                old = (old + ways) % mod;
            }
            cout << "old = " << old << endl;
            res = (res + mult * static_cast<ll>(i + 1) % mod * multSum[i]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}