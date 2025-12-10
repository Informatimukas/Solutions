#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    string s;
    int res = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        int mask = 0, n;
        vector<int> a;
        while (ss >> s)
            if (s[0] == '[') {
                n = s.length() - 2;
                for (int i = 0; i < n; i++)
                    if (s[i + 1] == '#')
                        mask |= 1 << i;
            } else if (s[0] == '(') {
                for (auto& ch : s)
                    if (!isdigit(ch))
                        ch = ' ';
                stringstream ss2(s);
                int num, cur = 0;
                while (ss2 >> num)
                    cur |= 1 << num;
                a.push_back(cur);
            }
        vector dp(1 << n, Inf);
        vector ndp(1 << n, Inf);
        dp[0] = ndp[0] = 0;
        for (auto& num : a) {
            for (int i = 0; i < 1 << n; i++)
                ndp[i ^ num] = min(ndp[i ^ num], dp[i] + 1);
            dp = ndp;
        }
        res += dp[mask];
    }
    cout << res << endl;
    return 0;
}
