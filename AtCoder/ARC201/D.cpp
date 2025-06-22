#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600006;

int T;
int n, m;
int a[Maxn];
int b[Maxn];
int cnt[Maxn];

void Add(int lef, int rig) {
    if (rig - lef >= n) {
        cnt[0]++;
        return;
    }
    if (lef < 0) {
        lef += n;
        rig += n;
    } else if (lef - n >= 0) {
        lef -= n;
        rig -= n;
    }
    lef %= n;
    rig %= n;
    if (lef < rig) {
        cnt[lef]++;
        cnt[rig]--;
    } else {
        cnt[lef]++;
        cnt[0]++;
        cnt[rig]--;
    }
}

bool Solve(int x) {
    fill(cnt, cnt + n, 0);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        while (a[l] < b[i]) l++;
        while (r < 2 * n && a[r] <= b[i] + x) r++;
        if (l >= r) return false;
        Add(l - i, r - i);
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += cnt[i];
        if (cur == n) return true;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            a[n + i] = a[i] + m;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            b[i] = (m - b[i]) % m;
        }
        sort(b, b + n);
        int lef = 0, rig = m - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        printf("%d\n", lef);
    }
    return 0;
}