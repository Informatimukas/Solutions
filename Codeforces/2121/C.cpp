#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int T;
int n, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector B(n, vector<int>(m));
        int mx = 0, bi = -1, bj = -1;
        vector<ii> cands;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                if (B[i][j] > mx) {
                    mx = B[i][j];
                    bi = -1;
                    bj = -1;
                    cands.clear();
                }
                if (B[i][j] == mx)
                    if (bi != -1) {
                        if (cands.empty() && i != bi && j != bj) {
                            cands.emplace_back(i, bj);
                            cands.emplace_back(bi, j);
                        }
                    } else bi = i, bj = j;
            }
        if (cands.empty()) {
            printf("%d\n", mx - 1);
            continue;
        }
        int res = 105;
        for (auto &[fst, snd] : cands) {
            int nmx = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int val = i == fst || j == snd? B[i][j] - 1: B[i][j];
                    nmx = max(nmx, val);
                }
            res = min(res, nmx);
        }
        printf("%d\n", res);
    }
    return 0;
}