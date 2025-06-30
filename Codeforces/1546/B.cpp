#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n, m;
char str[Maxn];
multiset<char> S[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            for (int j = 0; j < m; j++)
                S[j].insert(str[j]);
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%s", str);
            for (int j = 0; j < m; j++)
                S[j].erase(S[j].find(str[j]));
        }
        for (int j = 0; j < m; j++) {
            printf("%c", *S[j].begin());
            S[j].clear();
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}
