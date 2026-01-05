#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

const string docker = "docker";

int getValue(const string& s, int ind) {
    int res = 0;
    for (int i = 0; i < docker.length(); i++)
        res += s[ind + i] == docker[i];
    return res;
}

lli solveDP(const vector<int>& a, ll x) {
    vector<lli> dp(a.size() + 1);
    for (int i = 0; i < a.size(); i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        int ni = i + docker.length();
        if (ni <= a.size())
            dp[ni] = max(dp[ni], {dp[i].first + a[i] - x, dp[i].second + 1});
    }
    return dp[a.size()];
}

int Solve(const vector<int>& a, int need) {
    int n = a.size();
    int lef = 0, rig = 2 * n + 5;
    ll res;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        ll x = - n - 2 + mid;
        lli got = solveDP(a, - n - 2 + mid);
        if (got.second >= need) {
            res = got.first + need * x;
            lef = mid + 1;
        } else rig = mid - 1;
    }
    return need * docker.length() - res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> a(s.length());
        int nxt = 0, has = 0;
        for (int i = 0; i + docker.length() <= s.length(); i++) {
            a[i] = getValue(s, i);
            if (i >= nxt && a[i] == docker.length()) {
                ++has;
                nxt = i + docker.length();
            }
        }
        vector delt(s.length() + 1, 0);
        int n;
        cin >> n;
        int lim = s.length() / docker.length();
        while (n--) {
            int l, r;
            cin >> l >> r;
            r = min(r, lim);
            if (l <= r) {
                delt[l]++;
                delt[r + 1]--;
            }
        }
        int cur = 0, mx = 0;
        for (int& i : delt) {
            cur += i;
            i = cur;
            mx = max(mx, cur);
        }
        int res = s.length();
        for (int i = 0; i <= lim; i++)
            if (delt[i] == mx) {
                if (i <= has)
                    res = min(res, has - i);
                else {
                    res = min(res, Solve(a, i));
                    break;
                }
            }
        cout << res << "\n";
    }
    return 0;
}
