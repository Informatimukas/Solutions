#include <bits/stdc++.h>
using namespace std;

int T;
int seq[3];

int main() {
    scanf("%d", &T);
    while (T--) {
        int x; scanf("%d", &x);
        fill_n(seq, 3, 0);
        int res = 0;
        while (true) {
            sort(seq, seq + 3);
            if (seq[0] >= x) break;
            res++;
            seq[0] = 2 * seq[1] + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}