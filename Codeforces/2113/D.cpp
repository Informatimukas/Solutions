#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n;
int A[Maxn], B[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);
        set<int> S = {2 * n + 1};
        for (int i = 0; i < n; i++)
            S.insert(A[i]);
        int mx = 0, mn = 2 * n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            mn = min(mn, B[i]);
            if (*S.begin() > mn || min(*next(S.begin()), mx) > mn) {
                res = n - i;
                break;
            }
            int ind = n - 1 - i;
            mx = max(mx, A[ind]);
            S.erase(A[ind]);
        }
        printf("%d\n", res);
    }
    return 0;
}