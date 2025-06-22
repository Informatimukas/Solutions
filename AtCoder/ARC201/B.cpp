#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;

int T;
int n;
ll w;
vector<ll> my[Maxb];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &w);
        for (int i = 0; i < Maxb; i++)
            my[i].clear();
        for (int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            my[x].push_back(y);
        }
        ll res = 0;
        for (int i = 0; i < Maxb; i++) {
            ranges::sort(my[i]);
            if (!my[i].empty() && bool(w & 1ll << ll(i))) {
                res += my[i].back();
                my[i].pop_back();
            }
            if (i + 1 >= Maxb) continue;
            for (int j = int(my[i].size()) - 1; j > 0; j -= 2)
                my[i + 1].push_back(my[i][j] + my[i][j - 1]);
            if (my[i].size() % 2)
                my[i + 1].push_back(my[i][0]);
        }
        printf("%lld\n", res);
    }
    return 0;
}