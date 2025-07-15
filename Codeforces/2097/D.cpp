#include <bits/stdc++.h>
using namespace std;

constexpr int Maxb = 62;
constexpr int Maxn = 1000006;

int T;
int n;
char A[Maxn];
char B[Maxn];

set<int> Get(char A[]) {
    int len = n;
    while (len % 2 == 0) len /= 2;

}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        if (Get(A) == Get(B))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
