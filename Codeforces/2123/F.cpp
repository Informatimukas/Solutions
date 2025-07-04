#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

vector<int> primes[Maxn];
int T;
int n;
vector<int> my[Maxn];
int res[Maxn];

int main() {
    for (int i = 2; i < Maxn; i++)
        if (primes[i].empty())
            for (int j = i; j < Maxn; j += i)
                primes[j].push_back(i);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            my[i].clear();
            if (primes[i].back() == i) {
                my[i].push_back(i);
                continue;
            }
            int ind, best = Maxn;
            for (int j = primes[i].size() - 1; j >= 0; j--) {
                int p = primes[i][j];
                if (my[p].size() < best) {
                    best = my[p].size();
                    ind = p;
                    break;
                }
            }
            my[ind].push_back(i);
        }
        for (int i = 2; i <= n; i++) if (!my[i].empty()) {
            int lst = my[i].back();
            for (int j = 0; j < my[i].size(); j++) {
                res[my[i][j]] = lst;
                lst = my[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}