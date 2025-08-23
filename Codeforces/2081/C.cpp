#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxv = 4;

void Update(array<vector<ii>, Maxv> &P1, array<vector<ii>, Maxv> &P2, int p1, int p2,
    vector<vector<int>>& B, int& res) {
    array<int, 2> cur;
    ii v1 = P1[p1].back();
    P1[p1].pop_back();
    ii v2 = P2[p2].back();
    P2[p2].pop_back();
    cur[v1.second] = v1.first;
    cur[v2.second] = v2.first;
    B[cur[0]][cur[1]] ^= p1;
    P1[0].push_back(v1);
    P2[p2 ^ p1].push_back(v2);
    res++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector B(n, vector<int>(m));
        vector rows(n, 0);
        vector cols(m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                B[i][j] = ch - '0';
                rows[i] ^= B[i][j];
                cols[j] ^= B[i][j];
            }
        array<vector<ii>, Maxv> P1, P2;
        for (int i = 0; i < n; i++)
            P1[rows[i]].emplace_back(i, 0);
        for (int j = 0; j < m; j++)
            P2[cols[j]].emplace_back(j, 1);
        int res = 0;
        while (true) {
            bool stp = false;
            for (int i = 1; i <= 3 && !stp; i++)
                if (!P1[i].empty() && !P2[i].empty()) {
                    Update(P1, P2, i, i, B, res);
                    stp = true;
                }
            if (stp) continue;
            for (int z = 0; z < 2 && !stp; z++) {
                swap(P1, P2);
                for (int i = 1; i <= 3 && !stp; i++) if (!P1[i].empty())
                    for (int j = i + 1; j <= 3 && !stp; j++) if (!P1[j].empty()) {
                        int k = i ^ j;
                        if (!P2[k].empty()) {
                            Update(P1, P2, i, k, B, res);
                            Update(P2, P1, j, j, B, res);
                            stp = true;
                        }
                    }
            }
            if (stp) continue;
            for (int i = 1; i <= 3 && !stp; i++) if (!P1[i].empty())
                for (int j = 1; j <= 3 && !stp; j++) if (!P2[j].empty()) {
                    if (P1[i].size() < P2[j].size()) {
                        swap(P1, P2);
                        swap(i, j);
                    }
                    Update(P1, P2, i, j, B, res);
                    stp = true;
                }
            if (stp) continue;
            for (int z = 0; z < 2; z++) {
                swap(P1, P2);
                for (int i = 1; i <= 3; i++)
                    while (P1[i].size() >= 2) {
                        Update(P1, P2, i, 0, B, res);
                        Update(P2, P1, i, i, B, res);
                    }
                if (!P1[1].empty()) {
                    Update(P1, P2, 1, 0, B, res);
                    Update(P1, P2, 2, 1, B, res);
                    Update(P1, P2, 3, 3, B, res);
                }
            }
            break;
        }
        cout << res << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << B[i][j];
            cout << "\n";
        }
    }
    return 0;
}