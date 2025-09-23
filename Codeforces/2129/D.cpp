#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 205;
constexpr int mod = 998244353;

int Solve(int i, int j, int a, int b, const vector<int>& A,
    vector<vector<vector<vector<int>>>>& dp, const vector<vector<int>>& C) {
    if (i > j)
        return (a == 0 || a == A.size()) && (b == 0 || b == A.size());
    int& res = dp[i][j][a][b];
    if (res != -1)
        return res;
    res = 0;
    for (int k = i; k <= j; k++) {
        int s1 = k - i;
        int s2 = j - k;
        int na = a;
        int nb = b;
        if (i != 0 && (s1 <= s2 || j == A.size() - 1)) {
            if (na == 0)
                continue;
            if (na != A.size())
                na--;
        } else {
            if (nb == 0)
                continue;
            if (nb != A.size())
                nb--;
        }
        int ways = 0;
        if (A[k] == -1)
            ways = (ways + static_cast<ll>(Solve(i, k - 1, na, A.size(), A, dp, C)) *
                Solve(k + 1, j, A.size(), nb, A, dp, C)) % mod;
        else {
            for (int l = 0, r = A[k]; l <= A[k]; l++, r--)
                if (l <= s1 && r <= s2)
                    ways = (ways + static_cast<ll>(Solve(i, k - 1, na, l, A, dp, C)) *
                        Solve(k + 1, j, r, nb, A, dp, C)) % mod;
        }
        res = (res + static_cast<ll>(ways) * C[s1 + s2][s1]) % mod;
    }
    return res;
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
        vector<int> A(n);
        int sum = 0;
        for (auto& el : A) {
            cin >> el;
            sum += max(0, el);
        }
        if (sum > n - 1) {
            cout << "0\n";
            continue;
        }
        vector dp(n + 1, vector(n + 1, vector(n + 1, vector(n + 1, -1))));
        cout << Solve(0, n - 1, n, n, A, dp, C) << "\n";
    }
    return 0;
}
