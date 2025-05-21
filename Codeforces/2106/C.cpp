#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int lef = 0, rig = 2 * k;
        set <int> S;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if (b[i] == -1) {
                lef = max(lef, a[i]);
                rig = min(rig, a[i] + k);
            } else S.insert(a[i] + b[i]);
        }
        if (S.size() >= 2) printf("0\n");
        else if (S.size() == 1 && *S.begin() < lef || *S.begin() > rig)
            printf("0\n");
        else if (S.size() == 1) printf("1\n");
        else if (lef > rig) printf("0\n");
        else printf("%d\n", rig - lef + 1);
    }
    return 0;
}
