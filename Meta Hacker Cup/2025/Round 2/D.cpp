#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
constexpr int Maxk = 26;

void Sub(string& s) {
    int pnt = s.length() - 1;
    while (s[pnt] == '0')
        s[pnt--] = '9';
    s[pnt]--;
    if (s[0] == '0')
        s.erase(s.begin());
}

int Get(int j, int d, int z) {
    int rj = (j << 1) | 1;
    int nxt = d % z;
    if (rj & 1 << nxt)
        return -1;
    return (rj >> (nxt + 1)) | ((rj & ((1 << nxt) - 1)) << (z - nxt - 1));
}

int Solve(const vector<vector<int>>& dp, const string& s) {
    int z = dp.size();
    if (s.length() >= z) {
        int res = 0;
        for (int i = 1; i < z; i++)
            res = (res + dp[i][0]) % mod;
        return res;
    }
    int res = 0;
    for (int i = 1; i < s.length(); i++)
        res = (res + dp[i][0]) % mod;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int d = 1; d < s[i] - '0'; d++) {
            int got = Get(cur, d, z);
            if (got != -1)
                res = (res + dp[s.length() - 1 - i][got]) % mod;
        }
        int d = s[i] - '0';
        cur = Get(cur, d, z);
        if (cur == -1)
            return res;
    }
    res = (res + 1) % mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    vector<string> L(T), R(T);
    vector res(T, 0);
    vector my(Maxk, vector<int>());
    for (int i = 0; i < T; i++) {
        int k;
        cin >> L[i] >> R[i] >> k;
        Sub(L[i]);
        my[k].push_back(i);
    }
    for (int z = 2; z < Maxk; z++)
        if (!my[z].empty()) {
            vector dp(z, vector(1 << (z - 1), 1));
            vector neigh(1 << (z - 1), vector<int>());
            for (int j = 0; j < 1 << (z - 1); j++) {
                int rj = (j << 1) | 1;
                for (int d = 1; d < 10; d++) {
                    int nxt = d % z;
                    if (!(rj & 1 << nxt)) {
                        int nj = (rj >> (nxt + 1)) | ((rj & ((1 << nxt) - 1)) << (z - nxt - 1));
                        neigh[j].push_back(nj);
                    }
                }
            }
            for (int i = 1; i < z; i++)
                for (int j = 0; j < neigh.size(); j++) {
                    dp[i][j] = 0;
                    for (auto& x : neigh[j])
                        dp[i][j] = (dp[i][j] + dp[i - 1][x]) % mod;
                }
            for (auto& ind : my[z])
                res[ind] = (Solve(dp, R[ind]) - Solve(dp, L[ind]) + mod) % mod;
        }
    for (int tc = 0; tc < T; tc++)
        cout << "Case #" << tc + 1 << ": " << res[tc] << "\n";
    return 0;
}