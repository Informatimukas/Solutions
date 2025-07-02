#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        multiset<int> S;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            auto it = S.upper_bound(r);
            if (it != S.end())
                S.erase(it);
            S.insert(l);
            printf("%d%c", S.size(), i + 1 < n? ' ': '\n');
        }
    }
    return 0;
}