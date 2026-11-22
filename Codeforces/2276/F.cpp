#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

bool Solve(const vector<int>& a, int k) {
    vector tk(a.size(), false);
    vector<int> seq;
    for (int i = 1; i < a.size(); i++)
        if (!tk[i]) {
            int v = i, cnt = 0;
            while (!tk[v]) {
                tk[v] = true;
                ++cnt;
                v = a[v];
            }
            seq.push_back(cnt);
        }
    ranges::sort(seq, greater());
    vector dp(k + 1, vector(k + 1, Inf));
    dp[k][k] = 0;
    for (auto x : seq) {
        vector ndp(k + 1, vector(k + 1, Inf));
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++) {
                if (i >= x)
                    ndp[i - x][j] = min(ndp[i - x][j], dp[i][j]);
                if (j > 0)
                    ndp[i][j - 1] = min(ndp[i][j - 1], dp[i][j] + x - 1);
                else ndp[i][j] = min(ndp[i][j], dp[i][j]);
            }
        dp = ndp;
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            if (dp[i][j] <= k)
                return true;
    return false;
}

bool Win(const vector<int>& a, int k) {
    if (!Solve(a, k))
        return false;
    vector tk(a.size(), false);
    int ones = 0, spec = 0;
    vector<int> mid;
    for (int i = 1; i < a.size(); i++)
        if (!tk[i]) {
            int v = i, cnt = 0;
            while (!tk[v]) {
                tk[v] = true;
                ++cnt;
                v = a[v];
            }
            if (cnt > k + 1)
                return false;
            if (cnt == k + 1)
                ++spec;
            else if (cnt == 1)
                ++ones;
            else mid.push_back(cnt);
        }
    if (spec == 0)
        return true;
    int sum = 0;
    for (auto x : mid)
        sum += x;
    if (sum == 0)
        return ones % (k + 1) != 0;
    for (int j = 0; j <= ones && j + sum <= k; j++)
        if ((ones - j) % (k + 1) == 0)
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << (Win(a, k) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
