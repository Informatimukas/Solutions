#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1005;

int n, d;
int a[Maxn];

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(a[i] - a[j]) <= d)
                res++;
    printf("%d\n", 2 * res);
    return 0;
}