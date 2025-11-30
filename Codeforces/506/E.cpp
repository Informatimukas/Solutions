// Next steps: debug the solution with the new Solve implemented.
// The failing test case:
// aa
// 40000
// i = 0, j = 1, k = 1, n = 40000
// nw = 1981
// old = 6908
// The solution uses the fact that mod = 10007 is small.
#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 10007;
constexpr int Maxm = 100005;
constexpr int Maxd = 3;
constexpr int Maxt = 205;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int Solve(int a, int b, int c, int n, const vector<vector<int>>& ways13,
    const vector<vector<int>>& ways1, const vector<vector<int>>& ways23,
    const vector<vector<int>>& ways2, const vector<vector<int>>& big) {
    if (n % 2 && c == 0)
        return 0;
    int mult = n % 2 ? 26 : 1;
    n /= 2;
    int res = 0;
    if (a == 0)
        if (b == 0) {
            int rem = n % mod;
            int cur = 1;
            while (rem--)
                cur = cur * 26 % mod;
            res = cur * big[1 << 2][n / mod] % mod;
        } else if (c == 0)
            res = ways2[b][n % mod] * big[1 << 1][n / mod] % mod;
        else res = ways23[b][n % mod] * big[1 << 1 | 1 << 2][n / mod] % mod;
    else if (b == 0)
        if (c == 0)
            res = ways1[a][n % mod] * big[1 << 0][n / mod] % mod;
        else res = ways13[a][n % mod] * big[1 << 0 | 1 << 2][n / mod] % mod;
    else if (c == 0) {
        for (int i = 0; i < mod && i <= n; i++) {
            int j = (n - i) % mod;
            res = (res + ways1[a][i] * ways2[b][j] % mod *
                big[1 << 0 | 1 << 1][(n - i - j) / mod]) % mod;
        }
    } else {
        for (int i = 0; i < 2 * mod && i <= n; i++) {
            int j = (n - i) % mod;
            res = (res + ways13[a][i] * ways2[b][j] % mod *
                big[1 << 0 | 1 << 1 | 1 << 2][(n - i - j) / mod]) % mod;
        }
    }
    return res * mult % mod;
}

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

int Solve2(int a, int b, int c, int n) {
    if (n % 2 && c == 0)
        return 0;
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
    array pw = {24, 25, 26};
    vector tmp(1 << Maxd, vector(Maxm, vector(Maxd, 0)));
    vector big(1 << Maxd, vector(Maxm, 0));
    for (int i = 0; i < 1 << Maxd; i++) {
        tmp[i][0][0] = 1;
        for (int j = 0; j < Maxm; j++)
            for (int d = 0; d < Maxd; d++) {
                big[i][j] = (big[i][j] + tmp[i][j][d]) % mod;
                if (j + 1 < Maxm)
                    for (int nd = d; nd < Maxd; nd++)
                        if (i & 1 << nd)
                            tmp[i][j + 1][nd] = (tmp[i][j + 1][nd] + tmp[i][j][d] * pw[nd]) % mod;
            }
    }
    vector<int> inv(2 * mod + 5);
    for (int i = 1; i < inv.size(); i++)
        inv[i] = Inv(i);
    vector ways13(Maxt, vector(2 * mod, 0));
    vector ways23(Maxt, vector(2 * mod, 0));
    vector ways1(Maxt, vector(2 * mod, 0));
    vector ways2(Maxt, vector(2 * mod, 0));
    int bad = 1;
    for (int i = 0; i < mod; i++)
        bad = bad * 26 % mod;
    for (int a = 1; a < Maxt; a++) {
        int cur1 = 1, cur2 = 1;
        for (int i = 0; i < mod; i++) {
            if (i / mod == (i + a - 1) / mod) {
                ways13[a][i] = ways1[a][i] = cur1;
                ways23[a][i] = ways2[a][i] = cur2;
            }
            cur1 = cur1 * (a + i) % mod * inv[i + 1] % mod * 24 % mod;
            cur2 = cur2 * (a + i) % mod * inv[i + 1] % mod * 25 % mod;
        }
        int tot1 = 0, tot2 = 0;
        for (int i = 0; i < 2 * mod; i++) {
            tot1 = (26 * tot1 + ways13[a][i]) % mod;
            tot2 = (26 * tot2 + ways23[a][i]) % mod;
            if (a == 1 && i <= 10)
                cout << "tot2[" << i << "] = " << tot2 << endl;
            if (i - mod >= 0) {
                tot1 = (tot1 - ways13[a][i - mod] * bad % mod + mod) % mod;
                tot2 = (tot2 - ways23[a][i - mod] * bad % mod + mod) % mod;
            }
            ways13[a][i] = tot1;
            ways23[a][i] = tot2;
        }
    }
    int myres = 0;
    int cur = 1;
    for (int i = 0; i <= 9993; i++) {
        int tk = cur;
        for (int j = 1; j <= 9993 - i; j++)
            tk = tk * 26 % mod;
        myres = (myres + tk) % mod;
        cur = cur * 25 % mod;
    }
    cout << "myres = " << myres << endl;
    cout << ways23[1][9993] << endl;
    cout << big[6][1] << endl;
    string s;
    /*s = string(200, '.');
    for (int i = 0; i < s.length(); i++)
        s[i] = rand() % 26 + 'a';*/
    cin >> s;
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
                    if (cnt[i][j][k][z]) {
                        res = (res + cnt[i][j][k][z] *
                            Solve(i, j, k, n - i - z, ways13, ways1, ways23, ways2, big)) % mod;
                        int nw = Solve(i, j, k, n - i - z, ways13, ways1, ways23, ways2, big);
                        int old = Solve2(i, j, k, n - i - z);
                        if (nw != old) {
                            cout << "i = " << i << ", j = " << j << ", k = " << k << ", n = " << n - i - z << endl;
                            cout << "nw = " << nw << endl;
                            cout << "old = " << old << endl;
                            return 0;
                        }
                    }
    cout << res << "\n";
    return 0;
}