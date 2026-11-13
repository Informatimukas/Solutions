#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr ll Inf = 1000000000000000000ll;

ll waysEmpty(int n) {
    return static_cast<ll>(n) * (n + 1) / 2;
}

ll Solve1(int n) {
    int mid = n / 2;
    return waysEmpty(mid) + waysEmpty(n - 1 - mid);
}

ll Solve2(int n, int dif) {
    int rem = n - (dif + 1);
    int a = rem / 2;
    int b = rem - a;
    ll ways = waysEmpty(a) + waysEmpty(b) + waysEmpty(dif - 1);
    if (dif % 2)
        ways += static_cast<ll>(a + 1) * (b + 1);
    return ways;
}

ll solveInternal(int n, int dif, int dif2, int a) {
    int rem = n - (dif + 1);
    int b = rem - a;
    int c = dif2 - 1, d = dif - dif2 - 1;
    ll ways = waysEmpty(a) + waysEmpty(b) + waysEmpty(c) + waysEmpty(d);
    if (dif2 % 2)
        ways += static_cast<ll>(a + 1) * (d + 1);
    if ((dif - dif2) % 2)
        ways += static_cast<ll>(c + 1) * (b + 1);
    if (dif % 2 == 0 && dif2 % 2 == 0)
        ways += static_cast<ll>(a + 1) * (b + 1);
    return ways;
}

lli solveTernary(int n, int dif, int dif2, int l, int r) {
    if (r - l <= 3) {
        lli res = {Inf, l};
        for (int i = l; i <= r; i++)
            res = min(res, {solveInternal(n, dif, dif2, i), i});
        return res;
    }
    int p1 = (2 * l + r) / 3, p2 = (l + 2 * r) / 3;
    ll q1 = solveInternal(n, dif, dif2, p1);
    ll q2 = solveInternal(n, dif, dif2, p2);
    if (q1 <= q2)
        return solveTernary(n, dif, dif2, l, p2 - 1);
    return solveTernary(n, dif, dif2, p1 + 1, r);
}

lli Solve3(int n, int dif, int dif2) {
    return solveTernary(n, dif, dif2, 0, n - (dif + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll res = Solve1(n);
        vector wth = {n / 2};
        for (int i = 1; i < n; i++) {
            int dif = i;
            ll cand = Solve2(n, dif);
            if (cand < res) {
                res = cand;
                int a = (n - (dif + 1)) / 2;
                wth = {a, a + dif};
            }
            for (int dif2 = dif / 2 - 3; dif2 <= dif / 2 + 3; dif2++)
                if (dif2 > 0 && dif2 < dif) {
                    auto p = Solve3(n, dif, dif2);
                    if (p.first < res) {
                        res = p.first;
                        int a = p.second;
                        wth = {a, a + dif2, a + dif};
                    }
                }
        }
        string s(n, '0');
        for (auto x : wth)
            s[x] = '1';
        cout << s << "\n";
    }
    return 0;
}
