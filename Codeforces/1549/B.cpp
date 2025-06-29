#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n;
char A[Maxn];
char B[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        int res = 0, i;
        for (i = 0; i < n; )
            if (A[i] == '0') {
                if (B[i] == '1')
                    res++;
                i++;
            } else if (i + 1 < n) {
                if (B[i + 1] == '1') {
                    res++;
                    B[i + 1] = '0';
                }
                if (B[i] == '1' && A[i + 1] == '1') {
                    res++;
                    i += 2;
                } else i++;
            } else i++;
        printf("%d\n", res);
    }
    return 0;
}