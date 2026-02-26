#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector lef(n + 2, vector(n + 2, 0ll));
        vector rig(n + 2, vector(n + 2, vector(n + 2, 0ll)));
        lef[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                lef[i][j] = (lef[i][j] + lef[i - 1][j]) % mod;
                if (j < n && s[i - 1] == '(')
                    lef[i][j + 1] = (lef[i][j + 1] + lef[i - 1][j]) % mod;
            }
        rig[n + 1][0][0] = 1;
        for (int i = n; i >= 1; i--)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++) {
                    rig[i][j][k] = (rig[i][j][k] + rig[i + 1][j][k]) % mod;
                    if (j < n) {
                        if (s[i - 1] == ')' && k < n)
                            rig[i][j + 1][k + 1] = (rig[i][j + 1][k + 1] + rig[i + 1][j][k]) % mod;
                        if (s[i - 1] == '(' && k > 0)
                            rig[i][j + 1][k - 1] = (rig[i][j + 1][k - 1] + rig[i + 1][j][k]) % mod;
                    }
                }
        ll res = 0;
        for (int i = 1; i <= n; i++)
            if (s[i - 1] == ')')
                for (int j = 1; j <= n; j++)
                    for (int l = j + 3; l <= n; l += 2) {
                        ll totl = j + 1 + l;
                        res = (res + (totl - 2) * lef[i - 1][j] % mod * rig[i + 1][l][j - 1] % mod) % mod;
                    }
        cout << res << "\n";
    }
    return 0;
}
