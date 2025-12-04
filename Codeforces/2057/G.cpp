// Next steps: I could not come up with a constructive solution.
// I tried several greedy ideas, but they didn't work.
// The last one was trying to process the BFS tree + greedy, but it gets MLE.
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

const vector<ii> dirs = {{0, 0}, {-1, 0}, {0, -1},
    {1, 0}, {0, 1}};

void Fill(const vector<string>& B, vector<vector<bool>>& tk, int r, int c) {
    int n = B.size();
    int m = B[0].size();
    queue<ii> Q;
    tk[r][c] = true;
    Q.emplace(r, c);
    while (!Q.empty()) {
        auto [r, c] = Q.front();
        Q.pop();
        for (auto& [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == '#' && !tk[nr][nc]) {
                tk[nr][nc] = true;
                Q.emplace(nr, nc);
            }
        }
    }
}

int Count(const vector<string>& B, const vector<vector<bool>>& tk, int r, int c) {
    int n = B.size();
    int m = B[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] != '#')
        return 0;
    int res = 0;
    for (auto& [dr, dc] : dirs) {
        int nr = r + dr;
        int nc = c + dc;
        if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == '#' && !tk[nr][nc])
            ++res;
    }
    return res;
}

void Mark(vector<string>& B, vector<vector<bool>>& tk, int r, int c) {
    int n = B.size();
    int m = B[0].size();
    for (auto& [dr, dc] : dirs) {
        int nr = r + dr;
        int nc = c + dc;
        if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == '#' && !tk[nr][nc])
            tk[nr][nc] = true;
    }
    B[r][c] = 'S';
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
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        vector tk(n, vector(m, false));
        vector dist(n, vector(m, Inf));
        vector<ii> V(n * m);
        int vlen = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (B[i][j] == '#' && !tk[i][j]) {
                    dist[i][j] = 0;
                    V[vlen++] = {i, j};
                    Fill(B, tk, i, j);
                }
        for (int z = 0; z < vlen; z++) {
            auto [r, c] = V[z];
            for (auto& [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == '#' &&
                    dist[r][c] + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + 1;
                    V[vlen++] = {nr, nc};
                }
            }
        }
        for (auto& v : tk)
            ranges::fill(v, false);
        for (int i = vlen - 1; i >= 0; i--) {
            auto [r, c] = V[i];
            if (!tk[r][c]) {
                int best = Count(B, tk, r, c), br = r, bc = c;
                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] == '#' &&
                        dist[nr][nc] + 1 == dist[r][c]) {
                        int cand = Count(B, tk, nr, nc);
                        if (cand > best) {
                            best = cand;
                            br = nr;
                            bc = nc;
                        }
                    }
                }
                Mark(B, tk, br, bc);
            }
        }
        for (auto& x : B)
            cout << x << "\n";
    }
    return 0;
}
