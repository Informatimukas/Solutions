#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 2000000000;
constexpr int Maxb = 30;

void Update(map<int, int>& M, int key, int val) {
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        --it;
        if (it->second >= val)
            return;
        if (it->first < key)
            ++it;
    }
    while (it != M.end() && val >= it->second)
        M.erase(it++);
    M.emplace(key, val);
}

int Get(const map<int, int>& M, int key) {
    auto it = M.upper_bound(key);
    return it == M.begin() ? -Inf : prev(it)->second;
}

void Update(vector<map<int, int>>& st, int v, int l, int r, int x, int key, int val) {
    Update(st[v], key, val);
    if (l < r) {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, 2 * v, l, m, x, key, val);
        else Update(st, 2 * v + 1, m + 1, r, x, key, val);
    }
}

int Get(const vector<map<int, int>>& st, int v, int l, int r, int a, int b, int key) {
    if (l == a && r == b)
        return Get(st[v], key);
    int m = (l + r) / 2;
    int res = -Inf;
    if (a <= m)
        res = max(res, Get(st, 2 * v, l, m, a, min(m, b), key));
    if (m + 1 <= b)
        res = max(res, Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, key));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector lst(n + 1, array<int, Maxb>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < Maxb; j++)
            if (a[i] & 1 << j)
                lst[i][j] = i;
            else lst[i][j] = lst[i - 1][j];
    }
    vector<map<int, int>> st(4 * (n + 1));
    Update(st, 1, 0, n, 0, 0, 0);
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        int pos = i;
        while (pos) {
            int nxt = 0;
            for (int j = 0; j < Maxb; j++)
                if (!(cur & 1 << j))
                    nxt = max(nxt, lst[i][j]);
            int got = Get(st, 1, 0, n, nxt, pos - 1, cur);
            if (got >= 0)
                Update(st, 1, 0, n, i, cur, got + 1);
            cur |= a[nxt];
            pos = nxt;
        }
    }
    cout << Get(st, 1, 0, n, n, n, Inf) << "\n";
    return 0;
}
