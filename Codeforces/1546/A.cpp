#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 105;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector<int> big, small;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            while (a[i] > b[i]) {
                big.push_back(i);
                a[i]--;
            }
            while (a[i] < b[i]) {
                small.push_back(i);
                a[i]++;
            }
        }
        if (big.size() != small.size())
            printf("-1\n");
        else {
            printf("%d\n", big.size());
            for (int i = 0; i < big.size(); i++)
                printf("%d %d\n", big[i] + 1, small[i] + 1);
        }
    }
    return 0;
}