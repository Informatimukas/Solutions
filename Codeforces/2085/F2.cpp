#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

constexpr int Maxn = 400005;
constexpr int Inf = 1000000000;
constexpr ll bInf = 1000000000000000000ll;

int T;
int n, k;
int lst[Maxn];
vector<iii> seq;
lli mem[Maxn], BIT[Maxn];

void Add(int x, const lli& p) {
    for (int i = x; i <= n; i += i & -i) {
        BIT[i].first += p.first;
        BIT[i].second += p.second;
    }
}

lli Get(int x) {
    lli res = {0ll, 0};
    for (int i = x; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

ll Sum(int a, int b) {
    return static_cast<ll>(a + b) * (b - a + 1) / 2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill_n(lst, k + 1, -Inf);
        seq.clear();
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            seq.push_back({lst[a] + i, {lst[a], i}});
            lst[a] = i;
        }
        for (int i = 1; i <= k; i++)
            seq.push_back({lst[i] + Inf, {lst[i], Inf}});
        fill_n(BIT, n + 1, lli{0ll, 0});
        ranges::sort(seq);
        for (auto& [a, b]: seq | views::values)  {
            Add(max(1, a), {-a, 0});
            Add(min(n + 1, b), {a, 0});
        }
        copy(BIT, BIT + n + 1, mem);
        vector<vector<iii>> cur(seq.size() + 1);
        ll res = bInf;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = seq.size();
            int m = l + r >> 1;
            cur[m].push_back({i, {l, r}});
        }
        bool rep = true;
        while (rep) {
            rep = false;
            copy(mem, mem + n + 1, BIT);
            vector<vector<iii>> nxt(seq.size() + 1);
            for (int i = 0; i <= seq.size(); i++) {
                for (auto& [ind, p]: cur[i]) {
                    auto [l, r] = p;
                    auto got = Get(ind);
                    if (got.second == k / 2) {
                        int A = (k + 1) / 2;
                        int B = k / 2;
                        res = min(res, got.first +
                            Sum(ind - A + 1, ind) - Sum(ind + 1, ind + B));
                    } else if (got.second > k / 2) {
                        rep = true;
                        r = i - 1;
                        int m = l + r >> 1;
                        nxt[m].push_back({ind, {l, r}});
                    } else {
                        rep = true;
                        l = i + 1;
                        int m = l + r >> 1;
                        nxt[m].push_back({ind, {l, r}});
                    }
                }
                if (i < seq.size()) {
                    auto& [a, b] = seq[i].second;
                    Add(max(1, a), {a + b, 1});
                    Add(min(n + 1, b), {-a - b, -1});
                }
            }
            cur = std::move(nxt);
        }
        printf("%lld\n", res);
    }
    return 0;
}
