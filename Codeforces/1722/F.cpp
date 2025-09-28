#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Fill(int r, int c, vector<string>& B, vector<ii>& res) {
    if (r < 0 || r >= B.size() || c < 0 || c >= B[0].length() || B[r][c] == '.')
        return;
    B[r][c] = '.';
    res.emplace_back(r, c);
    for (int deltr = -1; deltr <= 1; deltr++)
        for (int deltc = -1; deltc <= 1; deltc++)
            if (deltr || deltc)
                Fill(r + deltr, c + deltc, B, res);
}

bool Solve(vector<string>& B) {
    for (int i = 0; i < B.size(); i++)
        for (int j = 0; j < B[i].length(); j++)
            if (B[i][j] == '*') {
                vector<ii> got;
                Fill(i, j, B, got);
                int rmin = ranges::min_element(got, {}, &ii::first)->first;
                int rmax = ranges::max_element(got, {}, &ii::first)->first;
                int cmin = ranges::min_element(got, {}, &ii::second)->second;
                int cmax = ranges::max_element(got, {}, &ii::second)->second;
                if (got.size() != 3 || rmin + 1 != rmax || cmin + 1 != cmax)
                    return false;
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
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        cout << (Solve(B) ? "YES" : "NO") << "\n";
    }
    return 0;
}