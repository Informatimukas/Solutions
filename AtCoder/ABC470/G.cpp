#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Get(const map<int, int>& M, int key) {
    return prev(M.upper_bound(key))->second;
}

ll Add(map<int, int>& M, int lef, int rig, int value) {
    if (lef >= rig)
        return 0;
    ll res = 0;
    int got = Get(M, lef);
    if (got >= value)
        return 0;
    M[lef] = got;
    M[rig] = Get(M, rig);
    auto it = M.find(lef);
    auto nit = next(it);
    while (it->first != rig && it->second < value) {
        res += static_cast<ll>(value - it->second) * (nit->first - it->first);
        M.erase(it++);
        ++nit;
    }
    M.emplace(lef, value);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> my(n + 1);
    map<int, int> M;
    for (int i = 1; i <= n + 1; i++)
        M[i] = i;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        my[x].push_back(i);
    }
    ll res = 0, cur = 0;
    for (int i = 0; i <= n; i++) {
        int lst = 1;
        for (auto el : my[i]) {
            cur += Add(M, lst, el, el);
            lst = el + 1;
        }
        cur += Add(M, lst, n + 1, n + 1);
        res += static_cast<ll>(n) * (n + 1) / 2 - cur;
    }
    cout << res << "\n";
    return 0;
}
