#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 2520;
constexpr ll Inf = 1000000000000000000ll;

struct matrix {

};

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
        for (int i = 0; i < n; i++) {
            dist[i][0][i] = 0;
            for (int j = 0; j <= Maxn; j++) {
                for (int k = 0; k < n; k++)
                    if (j % a[k] != b[k]) {
                        int nk = (k + 1) % n;
                        dist[i][j][nk] = min(dist[i][j][nk], dist[i][j][k] + 1);
                    }
                if (j >= Maxn) break;
                for (int k = 0; k < n; k++) {
                    int nk = (k + 1) % n;
                    if (j % a[k] != b[k])
                        dist[i][j][nk] = min(dist[i][j][nk], dist[i][j][k] + 1);
                    if ((j + 1) % a[k] != b[k])
                        dist[i][j + 1][nk] = min(dist[i][j + 1][nk], dist[i][j][k] + 1);
                }
            }
        }

    }
    return 0;
}
