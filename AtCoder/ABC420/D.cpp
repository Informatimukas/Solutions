#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = vector<int>;

constexpr int Maxf = 2;

bool validCell(const iii& p, const vector<string>& B) {
    int R = B.size(), C = B[0].size();
    if (p[0] < 0 || p[0] >= R || p[1] < 0 || p[1] >= C)
        return false;
    char typ = B[p[0]][p[1]];
    if (typ == '#' || typ == 'x' && !p[2] || typ == 'o' && p[2])
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C;
    cin >> R >> C;
    vector<string> B(R);
    ii st, en;
    for (int i = 0; i < R; i++) {
        cin >> B[i];
        for (int j = 0; j < C; j++)
            if (B[i][j] == 'S')
                st = {i, j};
            else if (B[i][j] == 'G')
                en = {i, j};
    }
    vector dist(R, vector(C, vector(Maxf, numeric_limits<int>::max())));
    dist[st.first][st.second][0] = 0;
    queue<iii> Q;
    Q.push({st.first, st.second, 0});
    const vector<ii> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    while (!Q.empty()) {
        auto v = Q.front();
        int curDist = dist[v[0]][v[1]][v[2]];
        Q.pop();
        if (ii{v[0], v[1]} == en) {
            cout << curDist << "\n";
            return 0;
        }
        for (auto& d : dirs) {
            iii u = {v[0] + d.first, v[1] + d.second, v[2]};
            if (!validCell(u, B)) continue;
            if (B[u[0]][u[1]] == '?')
                u[2] = !u[2];
            if (curDist + 1 < dist[u[0]][u[1]][u[2]]) {
                dist[u[0]][u[1]][u[2]] = curDist + 1;
                Q.push(u);
            }
        }
    }
    cout << "-1\n";
    return 0;
}
