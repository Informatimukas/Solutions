#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 50 * 50;

int T;
int n, m;
int A[Maxn], B[Maxn];
int res[Maxn];
bool reach[Maxn][Maxn];

bool Check(int col) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            reach[i][j] = i == j;
    for (int i = 0; i < m; i++)
        if (res[i] == col)
            reach[A[i]][B[i]] = reach[B[i]][A[i]] = true;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                reach[i][j] |= reach[i][k] & reach[k][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!reach[i][j])
                return true;
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        bool was1 = false, was2 = false;
        int spec = -1;
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            if (a > b) swap(a, b);
            A[i] = a; B[i] = b;
            if (a == 1 && b == 2) spec = i;
            else if (a == 1) {
                res[i] = 1;
                was1 = true;
            } else {
                res[i] = 2;
                was2 = true;
            }
        }
        int k = 2;
        if (!was1) {
            assert(spec != -1);
            res[spec] = 1;
        } else if (!was2) {
            assert(spec != -1);
            res[spec] = 2;
        } else if (spec != -1) {
            res[spec] = 1;
            if (!Check(1)) {
                res[spec] = 2;
                if (!Check(2)) {
                    res[spec] = 3;
                    k = 3;
                }
            }
        }
        printf("%d\n", k);
        for (int i = 0; i < m; i++)
            printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    }
    return 0;
}