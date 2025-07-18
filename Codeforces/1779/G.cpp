#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 3;
constexpr int Maxn = 100005;

int T;
int n;
char S[Maxd][Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < Maxd; i++)
            scanf("%s", S[i]);
        if (S[0][n - 1] == S[1][n - 1] && S[1][n - 1] == S[2][n - 1]) {
            printf("0\n");
            continue;
        }
        vector<int> res;
        for (int i = 0; i < Maxd; i++) {
            int pnt = n - 1;
            while (pnt >= 0 && S[i][pnt] == S[i][n - 1])
                pnt--;
            res.push_back(n - 1 - pnt);
            vector<int> oth;
            for (int j = 0; j < Maxd; j++)
                if (i != j)
                    oth.push_back(j);
            if (S[oth[0]][n - 1] == S[oth[1]][n - 1])
                res.push_back(n - 1 - pnt);
        }
        ranges::sort(res);
        printf("%d\n", min(n, res[0] + res[1]));
    }
    return 0;
}
