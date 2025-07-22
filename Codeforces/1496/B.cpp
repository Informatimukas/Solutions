#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;
set<int> S;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        S.clear();
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            S.insert(a);
        }
        int res = S.size();
        int mex = 0;
        while (S.contains(mex)) mex++;
        while (k > 0) {
            if (mex > *S.rbegin()) {
                res += k;
                break;
            }
            k--;
            int wr = (mex + *S.rbegin() + 1) / 2;
            if (S.insert(wr).second)
                res++;
            if (wr != mex)
                break;
            while (S.contains(mex)) mex++;
        }
        printf("%d\n", res);
    }
    return 0;
}