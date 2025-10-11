#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;
constexpr int Maxd = 4;
constexpr int dy[Maxd] = {-1, 0, 1, 0};
constexpr int dx[Maxd] = {0, -1, 0, 1};

struct pos {
    int r1, r2, c1, c2;
    int r, c;
};

pos Fix(pos p, int H, int W) {
    if (p.r < 0) {
        p.r1++;
        p.r++;
    } else if (p.r + p.r2 - p.r1 >= H) {
        p.r2--;
    } else if (p.c < 0) {
        p.c1++;
        p.c++;
    } else if (p.c + p.c2 - p.c1 >= W) {
        p.c2--;
    }
    return p;
}

bool Empty(const pos& p, vector<vector<vector<vector<bool>>>>& isEmpty) {
    return p.r1 > p.r2 || p.c1 > p.c2 || isEmpty[p.r1][p.r2][p.c1][p.c2];
}

bool Dirty(const pos& p, int tr, int tc, const vector<string>& B) {
    int r = tr - p.r + p.r1;
    int c = tc - p.c + p.c1;
    return p.r1 <= r && r <= p.r2 && p.c1 <= c && c <= p.c2 && B[r][c] == '#';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<string> B(H);
    int tr, tc;
    for (int i = 0; i < H; i++) {
        cin >> B[i];
        for (int j = 0; j < W; j++)
            if (B[i][j] == 'T') {
                tr = i;
                tc = j;
            }
    }
    vector isEmpty(H, vector(H, vector(W, vector(W, true))));
    for (int r1 = 0; r1 < H; r1++)
        for (int r2 = r1; r2 < H; r2++)
            for (int c1 = 0; c1 < W; c1++)
                for (int c2 = c1; c2 < W; c2++) {
                    vector<bool>::reference val = isEmpty[r1][r2][c1][c2];
                    for (int r = r1; r <= r2 && val; r++)
                        for (int c = c1; c <= c2 && val; c++)
                            val = B[r][c] != '#';
                }
    vector dist(H, vector(H, vector(W, vector(W, vector(H, vector(W, Inf))))));
    pos v = {0, H - 1, 0, W - 1, 0, 0};
    dist[v.r1][v.r2][v.c1][v.c2][v.r][v.c] = 0;
    queue<pos> Q;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        int d = dist[v.r1][v.r2][v.c1][v.c2][v.r][v.c];
        for (int i = 0; i < Maxd; i++) {
            pos u = v;
            u.r += dy[i];
            u.c += dx[i];
            u = Fix(u, H, W);
            if (Empty(u, isEmpty)) {
                cout << d + 1 << "\n";
                return 0;
            }
            if (!Dirty(u, tr, tc, B) && d + 1 < dist[u.r1][u.r2][u.c1][u.c2][u.r][u.c]) {
                dist[u.r1][u.r2][u.c1][u.c2][u.r][u.c] = d + 1;
                Q.push(u);
            }
        }
    }
    cout << "-1\n";
    return 0;
}
