#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Inf = 1000000007;
constexpr int Maxn = 200005;
constexpr int Maxm = 20;

int T;
int n;
ll s;
int x;
int a[Maxn];
int mx[Maxn][Maxm];
ll sum[Maxn];
map<ll, vector<int>> M;

int getMax(int l, int r) {
    int res = -Inf;
    for (int i = Maxm - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

int getLast(const vector<int> &seq, int rig) {
    return ranges::partition_point(seq, [rig](int el) {
        return getMax(el + 1, rig) >= x;
    }) - seq.begin();
}

int getFirst(const vector<int> &seq, int rig) {
    return ranges::partition_point(seq, [rig](int el) {
        return getMax(el + 1, rig) > x;
    }) - seq.begin();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld %d", &n, &s, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mx[i][0] = a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int j = 1; j < Maxm; j++)
            for (int i = 1; i + (1 << j) <= n + 1; i++)
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        M.clear();
        M[0].push_back(0);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            ll nd = sum[i] - s;
            auto it = M.find(nd);
            if (it != M.end())
                res += getLast(it->second, i) - getFirst(it->second, i);
            M[sum[i]].push_back(i);
        }
        printf("%lld\n", res);
    }
    return 0;
}