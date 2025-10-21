#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 10007;

struct matrix {
    vector<vector<int>> m;
    matrix(int n, int diag = 0): m(n, vector(n, 0)) {
        if (diag)
            for (int i = 0; i < n; i++)
                m[i][i] = diag;
    }
    matrix operator*(const matrix& oth) const {
        matrix res(m.size());
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m.size(); j++)
                for (int k = 0; k < m.size(); k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * oth.m[k][j]) % mod;
        return res;
    }
};

int Solve(int a, int b, int c, int n) {
    if (n % 2 && c == 0)
        return 0;
    cout << "Solve " << a << " " << b << " " << c << " " << n << endl;
    int mult = n % 2 ? 26 : 1;
    n /= 2;
    matrix R(a + b + c, 1), A(a + b + c);
    for (int i = 0; i < A.m.size(); i++)
        for (int j = i; j < A.m.size(); j++)
            if (j < a) A.m[j][i] = 24;
            else if (j < a + b) A.m[j][i] = 25;
            else A.m[j][i] = 26;
    while (n) {
        if (n & 1)
            R = R * A;
        n >>= 1;
        A = A * A;
    }
    int res = 0;
    for (int j = 0; j < R.m.size(); j++)
        res = (res + R.m[j][0]) % mod;
    return mult * res % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    s = string(200, '.');
    for (int i = 0; i < s.length(); i++)
        s[i] = rand() % 26 + 'a';
    //cin >> s;
    int n;
    cin >> n;
    vector dp(s.length() + 1, vector(s.length() + 1, vector(s.length() + 1, 0)));
    vector cnt(s.length() + 1, vector(s.length() + 1, vector(2, vector(2, 0))));
    dp[0][s.length() - 1][0] = 1;
    for (int l = s.length() - 1; l >= 0; l--)
        for (int i = 0, j = l; j < s.length(); i++, j++)
            for (int k = 0; k < s.length(); k++)
                if (dp[i][j][k]) {
                    if (s[i] != s[j]) {
                        dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;
                        dp[i][j - 1][k] = (dp[i][j - 1][k] + dp[i][j][k]) % mod;
                    } else if (l > 1)
                        dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + dp[i][j][k]) % mod;
                    else if (l == 1) {
                        int match = k + 1;
                        int lft = s.length() - 2 * match;
                        if (n - lft >= 0)
                            cnt[lft][match][1][0] = (cnt[lft][match][1][0] + dp[i][j][k]) % mod;
                    } else {
                        int match = k;
                        int lft = s.length() - 1 - 2 * match;
                        if (lft % 2 == n % 2 && n - lft >= 0)
                            cnt[lft][match + 1][0][0] = (cnt[lft][match + 1][0][0]
                                + dp[i][j][k]) % mod;
                        if (n - lft - 1 >= 0)
                            cnt[lft][match][1][1] = (cnt[lft][match][1][1] + dp[i][j][k]) % mod;
                    }
                }
    int res = 0;
    for (int i = 0; i < cnt.size(); i++)
        for (int j = 0; j < cnt[i].size(); j++)
            for (int k = 0; k < cnt[i][j].size(); k++)
                for (int z = 0; z < cnt[i][j][k].size(); z++)
                    if (cnt[i][j][k][z])
                        res = (res + cnt[i][j][k][z] * Solve(i, j, k, n - i - z)) % mod;
    cout << res << "\n";
    return 0;
}