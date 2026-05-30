#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000 - 1;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    for (auto& x : B)
        cin >> x;
    vector dist(h, vector(w, Inf));
    queue<ii> Q;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (B[i][j] == '#')
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (0 <= ni && ni < h && 0 <= nj && nj < w && 1 < dist[ni][nj] && B[ni][nj] != '#') {
                            dist[ni][nj] = 1;
                            Q.emplace(ni, nj);
                        }
                    }
    while (!Q.empty()) {
        ii v = Q.front();
        Q.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                ii u = {v.first + i, v.second + j};
                if (0 <= u.first && u.first < h && 0 <= u.second && u.second < w &&
                    dist[v.first][v.second] + 1 < dist[u.first][u.second]) {
                    dist[u.first][u.second] = dist[v.first][v.second] + 1;
                    Q.push(u);
                }
            }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            if (dist[i][j] % 2)
                cout << '.';
            else cout << "#";
        cout << "\n";
    }
    return 0;
}
