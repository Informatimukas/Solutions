#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

vector<int> dvs[Maxn];
int T;
int n;
int my[Maxn];

int main() {
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            dvs[j].push_back(i);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill_n(my, 2 * n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            my[a] = i;
        }
        int res = 0;
        for (int i = 1; i <= 2 * n; i++)
            for (int j: dvs[i])
                if (j != i / j && my[j] && my[i / j] && my[j] + my[i / j] == i)
                    res++;
        printf("%d\n", res / 2);
    }
    return 0;
}