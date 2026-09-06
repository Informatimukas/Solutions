#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using llii = pair<ll, ii>;

constexpr int Maxn = 2520;
constexpr ll Inf = 1000000000000000000ll;

struct matrix {
    vector<vector<ll>> mat;
    matrix(int n): mat(n, vector(n, Inf)) {}
    matrix operator*(const matrix& oth) const {
        matrix res(mat.size());
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat.size(); j++)
                for (int k = 0; k < mat.size(); k++)
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + oth.mat[k][j]);
        return res;
    }
};

void Solve(vector<vector<ll>>& dist, int v, int n, const vector<int>& a, const vector<int>& b) {
    dist[0][v] = 0;
    deque<ii> Q;
    Q.emplace_back(0, v);
    while (!Q.empty()) {
        ii cur = Q.front();
        Q.pop_front();
        ll d = dist[cur.first][cur.second];
        // wait
        int ntime = (cur.second + 1) % n;
        ii nxt = {cur.first, ntime};
        if (cur.first % a[cur.second] != b[cur.second] && d + 1 < dist[cur.first][ntime]) {
            dist[cur.first][ntime] = d + 1;
            Q.emplace_back(cur.first, ntime);
        }
        // go
        if (cur.first >= Maxn)
            continue;
        int npos = cur.first + 1;
        if (npos % a[cur.second] != b[cur.second] && d < dist[npos][ntime]) {
            dist[npos][ntime] = d;
            Q.emplace_front(npos, ntime);
        }
    }
}

matrix getMatrix(ll p, int n, const vector<vector<vector<ll>>>& dist) {
    matrix res(n), a(n);
    for (int i = 0; i < n; i++)
        res.mat[i][i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a.mat[i][j] = dist[i][Maxn][j];
    while (p) {
        if (p & 1)
            res = res * a;
        p >>= 1;
        a = a * a;
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
        int n;
        ll m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        vector dist(n, vector(Maxn + 1, vector(n, Inf)));
        for (int i = 0; i < n; i++)
            Solve(dist[i], i, n, a, b);
        auto got = getMatrix(m / Maxn, n, dist);
        ll res = Inf;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res = min(res, got.mat[0][i] + dist[i][m % Maxn][j]);
        if (res >= Inf) {
            cout << "-1\n";
            continue;
        }
        res += m;
        cout << res << "\n";
    }
    return 0;
}
