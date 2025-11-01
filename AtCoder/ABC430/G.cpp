#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxb = 60;

struct pos {
    ii val;
    int flag{0};
};

void downOn(vector<pos>& st, int v, int f) {
    st[v].val.first += f;
    st[v].flag += f;
}

void Down(vector<pos>& st, int v) {
    if (st[v].flag) {
        downOn(st, 2 * v, st[v].flag);
        downOn(st, 2 * v + 1, st[v].flag);
        st[v].flag = 0;
    }
}

ii Union(const ii &a, const ii &b) {
    if (a.first != b.first)
        return a.first > b.first ? a : b;
    return {a.first, a.second + b.second};
}

void Create(vector<pos>& st, int v, int l, int r) {
    st[v].val = {0, r - l + 1};
    if (l < r) {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        downOn(st, v, delt);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].val = Union(st[2 * v].val, st[2 * v + 1].val);
    }
}

ii Get(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v].val;
    Down(st, v);
    int m = (l + r) / 2;
    ii res = {0, 0};
    if (a <= m)
        res = Union(res, Get(st, 2 * v, l, m, a, min(m, b)));
    if (m + 1 <= b)
        res = Union(res, Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b));
    return res;
}

void Add(map<int, int>& M, int lef, int rig, vector<pos>& st, int n) {
    auto it = M.upper_bound(lef);
    if (it != M.begin()) {
        --it;
        if (it->second >= rig)
            return;
        lef = max(lef, it->second + 1);
        ++it;
    }
    while (it != M.end() && rig >= it->first)
        if (rig >= it->second) {
            Update(st, 1, 1, n, it->first, it->second, -1);
            M.erase(it++);
        } else {
            rig = min(rig, it->first - 1);
            break;
        }
    if (lef <= rig) {
        Update(st, 1, 1, n, lef, rig, 1);
        M.emplace(lef, rig);
    }
}

void Remove(map<int, int>& M, int lef, int rig, vector<pos>& st, int n) {
    auto it = M.upper_bound(lef);
    vector<ii> add;
    if (it != M.begin()) {
        --it;
        if (it->second >= lef) {
            Update(st, 1, 1, n, it->first, it->second, -1);
            if (it->first < lef)
                add.emplace_back(it->first, lef - 1);
            if (rig < it->second)
                add.emplace_back(rig + 1, it->second);
            M.erase(it++);
        } else ++it;
    }
    while (it != M.end() && rig >= it->first)
        if (rig >= it->second) {
            Update(st, 1, 1, n, it->first, it->second, -1);
            M.erase(it++);
        } else {
            add.emplace_back(rig + 1, it->second);
            Update(st, 1, 1, n, it->first, it->second, -1);
            M.erase(it);
            break;
        }
    for (auto& [a, b] : add) {
        Update(st, 1, 1, n, a, b, 1);
        M.emplace(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<pos> st(4 * (n + 1));
    Create(st, 1, 1, n);
    array<map<int, int>, Maxb> M{};
    while (q--) {
        int typ, l, r;
        cin >> typ >> l >> r;
        if (typ == 1) {
            int x;
            cin >> x;
            Add(M[x - 1], l, r, st, n);
        } else if (typ == 2) {
            int x;
            cin >> x;
            Remove(M[x - 1], l, r, st, n);
        } else {
            auto res = Get(st, 1, 1, n, l, r);
            cout << res.first << " " << res.second << endl;
        }
    }
    return 0;
}