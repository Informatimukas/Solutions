#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int getBest(const set<ii>& S) {
    if (S.size() <= 1)
        return 1;
    return prev(prev(S.end()))->first + 1;
}

void Update(int v, vector<set<ii>>& from, vector<set<ii>>& to,
    vector<map<int, int>>& tovals,
    int par, int val, int& res) {
    to[v].erase({tovals[v][par], par});
    from[par].erase({tovals[v][par], v});
    tovals[v][par] = val;
    to[v].emplace(val, par);
    from[par].emplace(val, v);
    res = max(res, getBest(to[v]));
    auto it = prev(to[v].end());
    while (it != to[v].begin() && it->second == par)
        --it;
    if (it->second == par)
        return;
    int cand = min(it->first, val) + 1;
    for (auto it2 = from[v].begin(); it2 != from[v].end() && it2->first < cand; ) {
        if (it->second == it2->second || par == it2->second) {
            ++it2;
            continue;
        }
        int nxt = it2->second;
        ++it2;
        Update(nxt, from, to, tovals, v, cand, res);
    }
    auto nit = it;
    if (nit == to[v].begin())
        return;
    --nit;
    if (nit->second == par) {
        if (nit == to[v].begin())
            return;
        --nit;
    }
    cand = min(nit->first, val) + 1;
    if (cand > tovals[it->second][v])
        Update(it->second, from, to, tovals, v, cand, res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<set<ii>> to(q + 2), from(q + 2);
    vector<map<int, int>> tovals(q + 2);
    int res = 1;
    for (int i = 2; i <= q + 1; i++) {
        int v;
        cin >> v;
        auto best = getBest(to[v]);
        Update(v, from, to, tovals, i, 1, res);
        Update(i, from, to, tovals, v, best, res);
        cout << res << (i + 1 <= q + 1 ? ' ' : '\n');
    }
    return 0;
}
