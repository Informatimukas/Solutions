#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> lli;

constexpr int Maxp = 320;
constexpr int Maxn = Maxp * Maxp;

int n, w;
ii ba[Maxn];
int c[Maxn];
deque<ll> X[Maxp];
deque<int> best[Maxp];
int add[Maxp];

void Prepare() {
    for (int i = 0; i < Maxp; i++)
        best[i].push_back((i + 1) * Maxp - 1);
}

lli Add(int to) {
    lli res = {0, 0};
    for (int i = 0; i < Maxp; i++) {
        if ((i + 1) * Maxp - 1 <= to) {
            add[i]++;
            while (!X[i].empty() && add[i] >= X[i].front()) {
                X[i].pop_front();
                best[i].pop_front();
            }
        } else if (i * Maxp <= to) {
            while (best[i].front() <= to) {
                X[i].pop_front();
                best[i].pop_front();
            }
            int from = i * Maxp;
            for (int j = to; j >= from; j--) {
                c[j]++;
                while (true) {
                    ll tp = static_cast<ll>(j) * c[j] - static_cast<ll>(best[i].front()) * c[best[i].front()];
                    if (tp < 0) break;
                    ll cand = tp / (best[i].front() - j) + 1;
                    if (cand <= add[i]) break;
                    if (X[i].empty() || cand < X[i].front()) {
                        X[i].push_front(cand);
                        best[i].push_front(j);
                        break;
                    }
                    best[i].pop_front();
                    X[i].pop_front();
                }
            }
        }
        int wh = best[i].front();
        res = max(res, {static_cast<ll>(wh) * (add[i] + c[wh]), wh});
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &ba[i].second, &ba[i].first);
    sort(ba, ba + n);
    Prepare();
    int lim = ba[n - 1].first + 1;
    int pnt = 0;
    lli res;
    for (int i = 0; i <= lim; i++) {
        while (pnt < n && ba[pnt].first < i) {
            res = Add(ba[pnt].second);
            pnt++;
        }
        printf("%lld %d\n", static_cast<ll>(n - pnt) * w * i + res.first, res.second);
    }
    return 0;
}
