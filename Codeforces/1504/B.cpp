#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;

int T;
int n;
char A[Maxn];
char B[Maxn];
bool ok[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A + 1);
        scanf("%s", B + 1);
        int st = 0;
        for (int i = 1; i <= n; i++) {
            st += A[i] == '1'? 1: -1;
            ok[i] = st == 0;
        }
        bool flag = false, fail = false;
        for (int i = n; i >= 1; i--) {
            char my = flag? A[i] == '0'? '1': '0': A[i];
            if (my != B[i])
                if (ok[i]) flag ^= true;
                else {
                    fail = true;
                    break;
                }
        }
        printf("%s\n", fail? "NO": "YES");
    }
    return 0;
}