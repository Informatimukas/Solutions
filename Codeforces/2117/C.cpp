#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];
int lst[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        fill_n(lst, n + 1, n);
        vector<ii> seq = {{n, n}};
        for (int i = n - 1; i >= 0; i--) {
            ii my = {i, i};
            while (lst[a[i]] > seq.back().second) {
                my.second = seq.back().second;
                seq.pop_back();
            }
            lst[a[i]] = i;
            seq.push_back(my);
        }
        printf("%d\n", int(seq.size()) - 1);
    }
    return 0;
}