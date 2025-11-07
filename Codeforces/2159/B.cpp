#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

template<typename T>
vector<vector<T>> changeRowsColumns(vector<vector<T>> B) {
    int n = B.size(), m = B[0].size();
    vector nB(m, vector<T>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nB[j][i] = B[i][j];
    return nB;
}

vector<vector<int>> Solve(const vector<vector<char>>& B) {
    int n = B.size(), m = B[0].size();
    vector res(n, vector(m, Inf));
    for (int l = n - 1; l > 0; l--)
        for (int i = n - 1 - l, j = n - 1; i >= 0; i--, j--) {
            for (int k = 0; k < m; k++)
                res[i + 1][k] = min(res[i + 1][k], res[i][k]);
            int lst = -1;
            for (int k = 0; k < m; k++)
                if (B[i][k] == '1' && B[j][k] == '1') {
                    if (lst != -1) {
                        int cand = (k - lst + 1) * (l + 1);
                        for (int z = lst; z <= k; z++) {
                            res[i][z] = min(res[i][z], cand);
                            res[i + 1][z] = min(res[i + 1][z], cand);
                        }
                    }
                    lst = k;
                }
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
        vector<vector<char>> B(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            B[i] = vector(s.begin(), s.end());
        }
        bool sw = n > m;
        if (sw)
            B = changeRowsColumns(std::move(B));
        auto res = Solve(B);
        if (sw)
            res = changeRowsColumns(std::move(res));
        for (auto& x : res)
            for (int i = 0; i < x.size(); i++)
                cout << (x[i] >= Inf ? 0 : x[i]) << (i + 1 < x.size() ? ' ' : '\n');
    }
    return 0;
}
