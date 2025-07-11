#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1005;

int T;
int n;
int a[Maxn];

bool Sorted() {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool found = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i && abs(a[i] - a[i - 1]) <= 1)
                found = true;
        }
        if (found) {
            printf("0\n");
            continue;
        }
        if (Sorted()) {
            printf("-1\n");
            continue;
        }
        reverse(a, a + n);
        if (Sorted()) {
            printf("-1\n");
            continue;
        }
        printf("1\n");
    }
    return 0;
}