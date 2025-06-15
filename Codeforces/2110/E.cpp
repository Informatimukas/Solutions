#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int lim = 1000000000;

int T;
int n;
map<ii, int> M;
map<int, set<ii>> neigh;

int main() {
    scanf("%d", &T);
    while (T--) {
        M.clear();
        neigh.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int v, p; scanf("%d %d", &v, &p);
            p += lim;
            M.insert({{v, p}, i});
            M.insert({{p, v}, i});
            neigh[v].emplace(p, i);
            neigh[p].emplace(v, i);
        }
        int st = neigh.begin()->first;
        int cnt = 0;
        for (auto &el: neigh)
            if (el.second.size() % 2) {
                st = el.first;
                cnt++;
            }
        if (cnt > 2) {
            printf("NO\n");
            continue;
        }
        vector<int> S = {st};
        vector<int> res;
        while (!S.empty()) {
            int v = S.back();
            if (neigh[v].empty()) {
                res.push_back(v);
                S.pop_back();
            } else {
                ii p = *neigh[v].begin();
                neigh[v].erase(neigh[v].begin());
                neigh[p.first].erase({v, p.second});
                S.push_back(p.first);
            }
        }
        bool ok = true;
        for (auto &el: neigh)
            if (!el.second.empty()) ok = false;
        if (!ok) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 0; i + 1 < res.size(); i++)
            printf("%d%c", M[{res[i], res[i + 1]}], i + 2 < res.size()? ' ': '\n');
    }
    return 0;
}