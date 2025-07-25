#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

constexpr int Maxn = 52;

int n;
int a, b;
ii d[Maxn];
ll tX, tY;
ll dX[Maxn], dY[Maxn];
ll resX[Maxn], resY[Maxn];

void writePrecise(ll &target, ii p, ll res[]) {
    if (target >= 0) {
        res[p.second] = p.first;
        target -= p.first;
    } else {
        res[p.second] = -p.first;
        target += p.first;
    }
}

void writeBest(ll &target, ii p, ll res[]) {
    ll tk = min(abs(target), static_cast<ll>(p.first));
    if (tk % 2 != p.first % 2)
        if (tk) tk--;
        else tk++;
    if (target >= 0) {
        res[p.second] = tk;
        target -= tk;
    } else {
        res[p.second] = -tk;
        target += tk;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    int st = (a + b) % 2;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &d[i].first);
        d[i].second = i;
        st = (st + d[i].first) % 2;
    }
    if (st) {
        printf("NO\n");
        return 0;
    }
    sort(d, d + n - 1);
    ll lef = d[n - 2].first, rig = d[n - 2].first;
    for (int i = 0; i < n - 2; i++) {
        lef -= d[i].first;
        rig += d[i].first;
    }
    tX = a + b, tY = a - b;
    bool sw;
    if (lef <= abs(tX) && abs(tX) <= rig && abs(tY) <= rig)
        sw = false;
    else if (lef <= abs(tY) && abs(tY) <= rig && abs(tX) <= rig) {
        sw = true;
        swap(tX, tY);
    } else {
        printf("NO\n");
        return 0;
    }
    writePrecise(tX, d[n - 2], dX);
    for (int i = 0; i < n - 2; i++) {
        writeBest(tX, d[i], dX);
        writePrecise(tY, d[i], dY);
    }
    writeBest(tY, d[n - 2], dY);
    ll curX = 0, curY = 0;
    for (int i = 0; i < n - 1; i++) {
        curX += dX[i];
        curY += dY[i];
        resX[i + 1] = (curX + curY) / 2;
        resY[i + 1] = (curX - curY) / 2;
        if (sw) swap(resX[i + 1], resY[i + 1]);
    }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%lld %lld\n", resX[i], resY[i]);
    return 0;
}
