#include <bits/stdc++.h>
using namespace std;

constexpr int Maxk = 13;
constexpr int Maxm = (1 << 12);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    vector queries(q, array<int, 3>{});
    vector byrig(n + 1, vector<int>());
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < queries[i].size(); j++)
            cin >> queries[i][j];
        byrig[queries[i][1]].push_back(i);
    }
    vector<int> res(q);
    vector dp(Maxk, vector(Maxm, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = Maxk - 2; j > 0; j--)
            for (int k = 0; k < Maxm; k++) {
                int nk = k ^ a[i];
                dp[j + 1][nk] = max(dp[j + 1][nk], dp[j][k]);
            }
        dp[1][a[i]] = max(dp[1][a[i]], i);
        for (auto& ind : byrig[i]) {
            int l = queries[ind][0], x = queries[ind][2];
            res[ind] = 1;
            while (res[ind] < Maxk && dp[res[ind]][x] < l)
                res[ind]++;
            if (res[ind] >= Maxk)
                res[ind] = 0;
        }
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << (i + 1 < q ? ' ' : '\n');
    return 0;
}
