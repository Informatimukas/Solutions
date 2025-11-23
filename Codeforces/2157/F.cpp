#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    n = 250000;//cin >> n;
    int need = n - 1;
    int k = 400;
    vector cnt(k + 1, 0);
    vector dp(n, Inf);
    vector<ii> par(n);
    dp[0] = 0;
    for (int j = 1; j <= k; j++)
        for (int i = n - 2; i >= 0; i--) {
            int cost = 0;
            for (int z = 1; z <= 30; z++) {
                cost += (z + 1) * j;
                int ni = min(i + z * j, n - 1);
                if (dp[i] + cost < dp[ni]) {
                    dp[ni] = dp[i] + cost;
                    par[ni] = {j, z};
                }
            }
        }
    cout << dp[need] << endl;
    while (need > 0) {
        cnt[par[need].first] = par[need].second;
        need -= par[need].first * par[need].second;
    }
    cout << "{";
    for (int i = 1; i <= k; i++)
        cout << cnt[i] << ",";
    cout << "}" << endl;
    return 0;
    /*    for (int i = n - 1; i >= 0; i--)
    int cand;
    for (int k = 400; k <= 600; k++) {
        cand = (k - 1) * 1000;
        int tk = 0;
        for (int z = 2; tk < need; z++)
            for (int j = 1; j <= k && tk < need; j++) {
                cand += z * j;
                cnt[j]++;
                tk += j;
            }
        cout << "k = " << k << ", cand = " << cand << endl;
    }
    return 0;
    int k = 550;
    vector res(k + 2, vector<ii>());
    res[k + 1].emplace_back(n, 0);
    int pnt = n - 1;
    for (int i = k; i > 0; i--)
        while (cnt[i]--)
            for (int j = i; j >= 1 && pnt > 0; j--) {
                res[j].emplace_back(pnt, res[j + 1].back().first - pnt);
                pnt--;
            }
    vector<ii> ans;
    for (int i = 1; i <= k; i++)
        for (auto& x : res[i])
            ans.push_back(x);
    int cost = 0;
    int lst = 0;
    for (auto& x : ans) {
        if (x.first > lst)
            cost += 1000;
        cost += x.second;
        lst = x.first;
    }
    cout << "cost = " << cost << endl;
    cout << "cand = " << cand << endl;*/
    return 0;
}