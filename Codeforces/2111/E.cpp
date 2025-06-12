#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 3;
constexpr int Maxn = 200005;

int T;
int n, q;
char str[Maxn];
set<int> S[Maxd][Maxd];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        scanf("%s", str);
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                S[i][j].clear();
        for (int i = 0; i < q; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            S[a - 'a'][b - 'a'].insert(i);
        }
        for (int i = 0; i < n; i++)
            if (str[i] == 'b') {
                if (!S[1][0].empty()) {
                    S[1][0].erase(S[1][0].begin());
                    str[i] = 'a';
                } else if (!S[1][2].empty() && !S[2][0].empty()
                            && *S[1][2].begin() < *S[2][0].rbegin()) {
                    S[2][0].erase(S[2][0].upper_bound(*S[1][2].begin()));
                    S[1][2].erase(S[1][2].begin());
                    str[i] = 'a';
                }
            } else if (str[i] == 'c') {
                if (!S[2][0].empty()) {
                    S[2][0].erase(S[2][0].begin());
                    str[i] = 'a';
                } else if (!S[2][1].empty() && !S[1][0].empty()
                            && *S[2][1].begin() < *S[1][0].rbegin()) {
                    S[1][0].erase(S[1][0].upper_bound(*S[2][1].begin()));
                    S[2][1].erase(S[2][1].begin());
                    str[i] = 'a';
                } else if (!S[2][1].empty()) {
                    S[2][1].erase(S[2][1].begin());
                    str[i] = 'b';
                }
            }
        printf("%s\n", str);
    }
    return 0;
}