#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;
constexpr int Maxn = 3005;

int getC(const vector<vector<int>>& C, int n, int k) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return C[n][k];
}

ll Solve(int mid, const vector<int>& p, const vector<vector<int>>& C) {
    int cur1 = 0, cur2 = mid - 1;
    int has = 0;
    ll res = 1;
    for (auto& x : p)
        if (x == -1)
            ++has;
        else {
            if (x >= mid) {
                int tk2 = x - cur2 - 1;
                int tk1 = has - tk2;
                res = res * getC(C, has, tk2) % mod;
                cur2 = x;
                cur1 += tk1;
            } else {
                int tk1 = x - cur1 - 1;
                int tk2 = has - tk1;
                res = res * getC(C, has, tk1) % mod;
                cur1 = x;
                cur2 += tk2;
            }
            has = 0;
        }
    int tk2 = static_cast<int>(p.size()) - cur2;
    res = res * getC(C, has, tk2) % mod;
    return res;
}

bool Identity(const vector<int>& p) {
    for (int i = 0; i < p.size(); i++)
        if (p[i] != -1 && p[i] != i + 1)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector C(Maxn, vector(Maxn, 0));
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto& x : p)
            cin >> x;
        ll res = 0;
        for (int i = 2; i <= n; i++)
            res = (res + Solve(i, p, C)) % mod;
        if (Identity(p))
            res = (res - (n - 2) + mod) % mod;
        cout << res << "\n";
    }
    return 0;
}
