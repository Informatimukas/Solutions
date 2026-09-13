#include <bits/stdc++.h>
using namespace std;

vector dx = {-1, 0, 1, 0};
vector dy = {0, -1, 0, 1};

struct UnionSet {
    int cnt;
    vector<int> siz, par, spec;
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    UnionSet(int n): cnt(n), siz(n, 1), par(n), spec(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    void addNew() {
        int s = siz.size();
        siz.push_back(1);
        par.push_back(s);
        spec.push_back(1);
        cnt++;
    }
    void addSmaller(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return;
        if (spec[b]) {
            spec[b] = 0;
            cnt--;
        }
    }
    void addEqual(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return;
        if (spec[a] && spec[b])
            cnt--;
        else if (spec[a] || spec[b]) {
            cnt--;
            spec[a] = spec[b] = 0;
        }
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        spec[a] |= spec[b];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector A(n, vector<int>(m));
        vector V(n, vector<int>(m));
        int N = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
                V[i][j] = N++;
            }
        UnionSet U(N);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int d = 0; d < dx.size(); d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        if (A[i][j] < A[ni][nj])
                            U.addSmaller(V[i][j], V[ni][nj]);
                        else if (A[i][j] == A[ni][nj])
                            U.addEqual(V[i][j], V[ni][nj]);
                }
        cout << U.cnt << "\n";
        int q;
        cin >> q;
        while (q--) {
            int r, c, delt;
            cin >> r >> c >> delt;
            r--; c--;
            U.addNew();
            U.addSmaller(N, V[r][c]);
            V[r][c] = N++;
            A[r][c] -= delt;
            for (int d = 0; d < dx.size(); d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (0 <= nr && nr < n && 0 <= nc && nc < m)
                    if (A[r][c] < A[nr][nc])
                        U.addSmaller(V[r][c], V[nr][nc]);
                    else if (A[r][c] == A[nr][nc])
                        U.addEqual(V[r][c], V[nr][nc]);
                    else U.addSmaller(V[nr][nc], V[r][c]);
            }
            cout << U.cnt << "\n";
        }
    }
    return 0;
}
