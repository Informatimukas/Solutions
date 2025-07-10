#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 1000000007;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res = static_cast<ll>(res) * (n - k + i) % mod * Inv(i) % mod;
    }
    return res;
}

int T;
int a, b, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &k);
        int n = (static_cast<ll>(a - 1) * k + 1) % mod;
        int m = (static_cast<ll>(C(n, a)) * k % mod * (b - 1) + 1) % mod;
        printf("%d %d\n", n, m);
    }
    return 0;
}
