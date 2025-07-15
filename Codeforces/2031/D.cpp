#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 500005;

int T;
int n;
int a[Maxn];
int par[Maxn], siz[Maxn];
int mx[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b) {
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    mx[a] = max(mx[a], mx[b]);
    par[b] = a;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<int> S;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            par[i] = i; siz[i] = 1;
            mx[i] = a[i];
            while (!S.empty() && mx[getPar(S.back())] > a[i]) {
                unionSet(S.back(), i);
                S.pop_back();
            }
            S.push_back(i);
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", mx[getPar(i)], i + 1 < n? ' ': '\n');
    }
    return 0;
}