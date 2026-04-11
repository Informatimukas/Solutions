#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr ll lim = 1e16;

vector<vector<ll>> computeDown(const vector<vector<int>>& B) {
    vector res(B.size(), vector<ll>(B[0].size()));
    for (int i = 0; i < B.size(); i++)
        for (int j = 0; j < B[i].size(); j++)
            if (i == 0 && j == 0)
                res[i][j] = B[i][j];
            else {
                res[i][j] = -lim;
                if (i)
                    res[i][j] = max(res[i][j], res[i - 1][j]);
                if (j)
                    res[i][j] = max(res[i][j], res[i][j - 1]);
                res[i][j] += B[i][j];
            }
    return res;
}

vector<vector<ll>> computeUp(const vector<vector<int>>& B) {
    vector res(B.size(), vector<ll>(B[0].size()));
    for (int i = B.size() - 1; i >= 0; i--)
        for (int j = B[i].size() - 1; j >= 0; j--)
            if (i == B.size() - 1 && j == B[i].size() - 1)
                res[i][j] = B[i][j];
            else {
                res[i][j] = -lim;
                if (i + 1 < B.size())
                    res[i][j] = max(res[i][j], res[i + 1][j]);
                if (j + 1 < B[i].size())
                    res[i][j] = max(res[i][j], res[i][j + 1]);
                res[i][j] += B[i][j];
            }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector B(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> B[i][j];
        auto L = computeDown(B);
        auto R = computeUp(B);
        vector<array<lli, 2>> best(n + m);
        for (int i = 0; i < n + m; i++)
            best[i][0] = best[i][1] = {-lim, 0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                ll val = L[i][j] + R[i][j] - B[i][j];
                lli p = {val, B[i][j]};
                int ind = i + j;
                if (p > best[ind][0])
                    best[ind][1] = best[ind][0], best[ind][0] = p;
                else if (p > best[ind][1])
                    best[ind][1] = p;
            }
        ll res = lim;
        for (int i = 0; i < n + m - 1; i++)
            if (best[i][0].second <= 0)
                res = min(res, best[i][0].first);
            else res = min(res, max(best[i][0].first - 2 * best[i][0].second,
                        best[i][1].first));
        cout << res << "\n";
    }
    return 0;
}