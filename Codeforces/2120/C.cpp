#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 1000006;

int T;
int n;
ll m;
vector<int> nxt[Maxn];
vector<int> seq;

void addSeq(int v) {
    seq.push_back(v);
    for (int i = 0; i < nxt[v].size(); i++)
        addSeq(nxt[v][i]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &m);
        ll lef = n, rig = static_cast<ll>(n) * (n + 1) / 2;
        if (m < lef || m > rig) {
            printf("-1\n");
            continue;
        }
        m = rig - m;
        for (int i = 1; i <= n; i++)
            nxt[i].clear();
        seq.clear();
        for (int i = n; i >= 1; i--) {
            ll tk = min(m, static_cast<ll>(i - 1));
            if (tk > 0) {
                nxt[i - tk].push_back(i);
                m -= tk;
            } else addSeq(i);
        }
        printf("%d\n", seq[0]);
        for (int i = 0; i + 1 < seq.size(); i++)
            printf("%d %d\n", seq[i], seq[i + 1]);
    }
    return 0;
}