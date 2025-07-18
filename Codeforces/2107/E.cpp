#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int T;
int n;
ll k;
vector<ii> seq;

bool Solve(int root, ll lft) {
    for (int i = root + 1; i <= n; i++) {
        ll has = static_cast<ll>(n - i + 1) * (n - i) / 2;
        seq.emplace_back(root, i);
        if (has <= lft + 1) {
            lft -= has;
            return Solve(i, lft);
        }
    }
    return abs(lft) <= 1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        seq.clear();
        if (Solve(1, k)) {
            printf("Yes\n");
            for (auto &[a, b]: seq)
                printf("%d %d\n", a, b);
        } else printf("No\n");
    }
    return 0;
}
