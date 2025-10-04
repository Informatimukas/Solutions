#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxn = 502;

struct Query {
    int l, r, c;
    ll res;
};

void Solve(int l, int r, vector<array<ll, Maxn>>& dp, const vector<ii>& items,
    vector<Query>& queries, const vector<int>& seq) {
    if (l == r) {
        for (auto& ind : seq)
            queries[ind].res = items[l].first <= queries[ind].c ? items[l].second : 0;
        return;
    }
    int m = (l + r) / 2;
    vector<int> lef, mid, rig;
    for (auto& ind : seq)
        if (queries[ind].r <= m)
            lef.push_back(ind);
        else if (queries[ind].l >= m + 1)
            rig.push_back(ind);
        else mid.push_back(ind);
    if (!lef.empty())
        Solve(l, m, dp, items, queries, lef);
    if (!rig.empty())
        Solve(m + 1, r, dp, items, queries, rig);
    if (mid.empty())
        return;
    for (int j = 0; j < Maxn; j++)
        dp[m][j] = items[m].first <= j ? items[m].second : 0;
    for (int i = m - 1; i >= l; i--)
        for (int j = 0; j < Maxn; j++) {
            dp[i][j] = dp[i + 1][j];
            if (items[i].first <= j)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - items[i].first] + items[i].second);
        }
    for (int j = 0; j < Maxn; j++)
        dp[m + 1][j] = items[m + 1].first <= j ? items[m + 1].second : 0;
    for (int i = m + 2; i <= r; i++)
        for (int j = 0; j < Maxn; j++) {
            dp[i][j] = dp[i - 1][j];
            if (items[i].first <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i].first] + items[i].second);
        }
    for (auto& ind : mid) {
        auto& quer = queries[ind];
        for (int i = 0; i <= quer.c; i++)
            quer.res = max(quer.res, dp[quer.l][i] + dp[quer.r][quer.c - i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector dp(n + 1, array<ll, Maxn>());
    vector<ii> items(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> items[i].first >> items[i].second;
    int q;
    cin >> q;
    vector<Query> quer(q);
    for (auto& x : quer)
        cin >> x.l >> x.r >> x.c;
    vector<int> seq(q);
    iota(seq.begin(), seq.end(), 0);
    Solve(1, n, dp, items, quer, seq);
    for (auto& q : quer)
        cout << q.res << "\n";
    return 0;
}
