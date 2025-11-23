#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Solve(const vector<int>& X, const vector<int>& Y, vector<vector<int>>& B) {
    int n = X.size();
    int m = Y.size();
    vector myX(n * m + 1, vector<int>());
    vector myY(n * m + 1, vector<int>());
    for (int i = 0; i < n; i++)
        myX[X[i]].push_back(i);
    for (int j = 0; j < m; j++)
        myY[Y[j]].push_back(j);
    vector<ii> seq;
    vector<int> hasX, hasY;
    for (int i = n * m; i > 0; i--) {
        if (myX[i].size() > 1 || myY[i].size() > 1)
            return false;
        if (myX[i].size() == 1 && myY[i].size() == 1) {
            int row = myX[i][0], col = myY[i][0];
            B[row][col] = i;
            for (auto& x : hasX)
                seq.emplace_back(x, col);
            for (auto& y : hasY)
                seq.emplace_back(row, y);
            hasX.push_back(row);
            hasY.push_back(col);
        } else if (myX[i].size() == 1) {
            int row = myX[i][0];
            if (hasY.empty())
                return false;
            B[row][hasY[0]] = i;
            for (int z = 1; z < hasY.size(); z++)
                seq.emplace_back(row, hasY[z]);
            hasX.push_back(row);
        } else if (myY[i].size() == 1) {
            int col = myY[i][0];
            if (hasX.empty())
                return false;
            B[hasX[0]][col] = i;
            for (int z = 1; z < hasX.size(); z++)
                seq.emplace_back(hasX[z], col);
            hasY.push_back(col);
        } else {
            if (seq.empty())
                return false;
            B[seq.back().first][seq.back().second] = i;
            seq.pop_back();
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> X(n), Y(m);
        for (auto& x : X)
            cin >> x;
        for (auto& x : Y)
            cin >> x;
        vector B(n, vector<int>(m));
        if (Solve(X, Y, B)) {
            cout << "Yes\n";
            for (auto & i : B)
                for (int j = 0; j < i.size(); j++)
                    cout << i[j] << (j + 1 < i.size() ? ' ' : '\n');
        } else cout << "No\n";
    }
    return 0;
}