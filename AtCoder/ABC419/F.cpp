#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;
constexpr int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    set<string> S;
    S.insert("");
    for (auto& x : a) {
        cin >> x;
        for (int i = 1; i <= x.length(); i++)
            S.insert(x.substr(0, i));
    }
    vector states(S.begin(), S.end());
    vector nxt(states.size(), vector(Maxl, 0));
    vector statesVals(states.size(), 0);
    for (int i = 0; i < nxt.size(); i++) {
        for (int j = 0; j < n; j++)
            if (states[i].find(a[j]) != string::npos)
                statesVals[i] |= 1 << j;
        for (int j = 0; j < Maxl; j++) {
            string nw = states[i] + string(1, 'a' + j);
            while (true) {
                auto it = S.find(nw);
                if (it != S.end()) {
                    nxt[i][j] = distance(states.begin(), ranges::lower_bound(states, nw));
                    break;
                }
                nw.erase(nw.begin());
            }
        }
    }
    vector dp(l + 1, vector(states.size(), vector(1 << n, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < states.size(); j++)
            for (int k = 0; k < 1 << n; k++)
                for (int z = 0; z < Maxl; z++) {
                    int nj = nxt[j][z];
                    int nk = k | statesVals[nj];
                    dp[i + 1][nj][nk] = (dp[i + 1][nj][nk] + dp[i][j][k]) % mod;
                }
    int res = 0;
    for (int j = 0; j < states.size(); j++)
        res = (res + dp[l][j][(1 << n) - 1]) % mod;
    cout << res << "\n";
    return 0;
}