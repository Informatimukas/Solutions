#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n;
int res[Maxn];
bool tk[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res[1] = 1;
        fill_n(tk, n + 1, false);
        for (int i = n; i >= 2; i--) if (!tk[i]) {
            int my = i;
            for (int j = i + i; j <= n; j += i)
                if (!tk[j]) {
                    res[j] = my;
                    my = j;
                    tk[j] = true;
                }
            res[i] = my;
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}