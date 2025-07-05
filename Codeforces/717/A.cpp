#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 1000000007;
constexpr int Maxk = 205;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1ll)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

struct radNumber {
    int a, b;
    radNumber operator+(const radNumber &oth) const {
        return {(a + oth.a) % mod, (b + oth.b) % mod};
    }
    radNumber operator-(const radNumber &oth) const {
        return {(a - oth.a + mod) % mod, (b - oth.b + mod) % mod};
    }
    radNumber operator*(const radNumber &oth) const {
        radNumber res;
        res.a = (static_cast<ll>(a) * oth.a + static_cast<ll>(b) * oth.b % mod * 5ll) % mod;
        res.b = (static_cast<ll>(a) * oth.b + static_cast<ll>(b) * oth.a) % mod;
        return res;
    }
    radNumber operator/(const radNumber &oth) const {
        radNumber neg = {oth.a, (mod - oth.b) % mod};
        radNumber tp = *this * neg;
        radNumber bot = oth * neg;
        assert(bot.b == 0);
        assert(bot.a != 0);
        int inv = Inv(bot.a);
        tp.a = static_cast<ll>(tp.a) * inv % mod;
        tp.b = static_cast<ll>(tp.b) * inv % mod;
        return tp;
    }
    radNumber operator^(ll p) const {
        radNumber res = {1, 0}, a = *this;
        while (p) {
            if (p & 1ll)
                res = res * a;
            a = a * a;
            p >>= 1;
        }
        return res;
    }
};

radNumber q1 = radNumber({1, 1}) / radNumber({2, 0});
radNumber q2 = radNumber({1, mod - 1}) / radNumber({2, 0});

typedef pair<radNumber, radNumber> rr;

rr powerSum(ll n, const radNumber &a) {
    if (n == 1)
        return {radNumber{1, 0}, a};
    else {
        rr got = powerSum(n / 2, a);
        radNumber fir = (got.second + radNumber{1, 0}) * got.first;
        radNumber cur = got.second * got.second;
        if (n % 2) {
            fir = fir + cur;
            cur = cur * a;
        }
        return {fir, cur};
    }
}

int C[Maxk][Maxk];
int k;
ll l, r;

int Solve(ll n, int k) {
    radNumber res = {0, 0};
    for (int i = 0; i <= k; i++) {
        radNumber com = (q1 ^ i) * (q2 ^ (k - i));
        radNumber got = powerSum(n + 1, com).first;
        got = got * radNumber{C[k][i], 0};
        if ((k - i) % 2) res = res - got;
        else res = res + got;
    }
    res = res / (radNumber{0, 1} ^ k);
    assert(res.b == 0);
    return res.a;
}

int solveAll(ll n, int k) {
    deque<int> D = {1};
    for (int i = 0; i < k; i++) {
        D.push_front(0);
        for (int j = 1; j < D.size(); j++) {
            int got = static_cast<ll>(D[j]) * (mod - i) % mod;
            D[j - 1] = (D[j - 1] + got) % mod;
        }
    }
    int sum = 0;
    for (int i = 0; i < D.size(); i++)
        sum = (sum + static_cast<ll>(D[i]) * Solve(n, i)) % mod;
    for (int i = 2; i <= k; i++)
        sum = static_cast<ll>(sum) * Inv(i) % mod;
    return sum;
}

int main() {
    for (int i = 0; i < Maxk; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %lld %lld", &k, &l, &r);
    int res = (solveAll(r + 2, k) - solveAll(l + 1, k) + mod) % mod;
    printf("%d\n", res);
    return 0;
}