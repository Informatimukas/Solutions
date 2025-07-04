#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n, k;
char str[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += str[i] == '1';
        }
        if (cnt <= k || 2 * k > n)
            printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}