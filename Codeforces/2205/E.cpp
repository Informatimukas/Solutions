#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector mx(n, vector<short>(n, 0));
        vector allowed(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            vector delt(i + 1, 0);
            for (int j = 0; j < i; j++)
                if (a[j] == a[i]) {
                    mx[i][j] = 1;
                    if (j > 0)
                        mx[i][j] += mx[i - 1][j - 1];
                    delt[j - mx[i][j] + 1]++;
                    delt[j + 1]--;
                }
            int cur = 0;
            for (int j = 0; j <= i; j++) {
                cur += delt[j];
                allowed[i][j] = cur == 0;
            }
        }
        vector res(n + 1, 0);
        res[n] = 1;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (allowed[j][i])
                    res[i] = (res[i] + res[j + 1]) % mod;
        cout << res[0] << "\n";
    }
    return 0;
}
