#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct UnionSet {
    vector<int> par, siz;
    vector<ii> ops;
    UnionSet(int n): par(n + 1), siz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : getPar(par[x]); }
    bool unionSet(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return false;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        ops.emplace_back(a, b);
        return true;
    }
    void Undo(int len) {
        while (ops.size() > len) {
            auto& [a, b] = ops.back();
            siz[a] -= siz[b];
            par[b] = b;
            ops.pop_back();
        }
    }
};

void Add(int typ, int a, int b, UnionSet& A, UnionSet& AB, int& cur) {
    if (typ == 0) {
        if (!A.unionSet(a, b))
            return;
        if (!AB.unionSet(a, b))
            cur--;
    } else if (AB.unionSet(a, b))
            cur++;
}

void Solve(int lef, int rig, const vector<int>& oth, const vector<array<int, 3>>& seq,
    UnionSet& A, UnionSet& AB, vector<int>& res) {
    static int cur = 0;
    int alen = A.ops.size();
    int ablen = AB.ops.size();
    int memCur = cur;
    if (lef == rig) {
        if (oth[lef] > lef)
            Add(seq[lef][0], seq[lef][1], seq[lef][2], A, AB, cur);
        res[lef] = cur;
        A.Undo(alen);
        AB.Undo(ablen);
        cur = memCur;
        return;
    }
    int m = lef + rig >> 1;
    for (int i = m + 1; i <= rig; i++)
        if (oth[i] < lef)
            Add(seq[i][0], seq[i][1], seq[i][2], A, AB, cur);
    Solve(lef, m, oth, seq, A, AB, res);
    A.Undo(alen);
    AB.Undo(ablen);
    cur = memCur;
    for (int i = lef; i <= m; i++)
        if (oth[i] > rig)
            Add(seq[i][0], seq[i][1], seq[i][2], A, AB, cur);
    Solve(m + 1, rig, oth, seq, A, AB, res);
    A.Undo(alen);
    AB.Undo(ablen);
    cur = memCur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    array<map<ii, int>, 2> M;
    vector<int> oth(q);
    vector<array<int, 3>> seq(q);
    for (int i = 0; i < q; i++) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        int typ = ch - 'A';
        if (x > y) swap(x, y);
        seq[i] = {typ, x, y};
        auto it = M[typ].find({x, y});
        if (it == M[typ].end())
            M[typ].insert({{x, y}, i});
        else {
            oth[it->second] = i;
            oth[i] = it->second;
            M[typ].erase(it);
        }
    }
    for (int typ = 0; typ < M.size(); typ++)
        for (auto& [key, ind] : M[typ]) {
            oth[ind] = oth.size();
            seq.push_back({typ, key.first, key.second});
            oth.push_back(ind);
        }
    UnionSet A(n), AB(n);
    vector<int> res(oth.size());
    Solve(0, oth.size() - 1, oth, seq, A, AB, res);
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
    return 0;
}