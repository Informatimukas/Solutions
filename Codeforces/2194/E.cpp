#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

bool Check(vector<vector<int>>& B, const vector<array<int, 3>>& seq, ll x) {
    auto L = computeDown(B);
    if (L.back().back() <= x)
        return true;
    auto R = computeUp(B);
    for (auto& arr : seq) {
        if (arr[0] <= 0)
            break;
        int r = arr[1], c = arr[2];
        ll cur = L[r][c] + R[r][c] - B[r][c];
        if (cur > x) {
            B[r][c] = -B[r][c];
            L = computeDown(B);
            auto res = L.back().back() <= x;
            B[r][c] = -B[r][c];
            return res;
        }
    }
    return false;
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
        vector<array<int, 3>> seq;
        seq.reserve(n * m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
                seq.push_back({B[i][j], i, j});
            }
        ranges::sort(seq, greater());
        ll lef = -lim, rig = lim;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            if (Check(B, seq, mid))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
