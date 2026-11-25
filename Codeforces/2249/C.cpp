#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct node {
    int my{0}, mx{0};
};

int Get(const node& v) { return v.my + v.mx; }

void Add(vector<node>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        st[v].my += delt;
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Add(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Add(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].mx = max(Get(st[2 * v]), Get(st[2 * v + 1]));
    }
}

void Add(vector<vector<ii>>& seq, int v, int l, int r, int a, int b, ii p) {
    if (l == a && r == b)
        seq[v].push_back(p);
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Add(seq, 2 * v, l, m, a, min(m, b), p);
        if (m + 1 <= b)
            Add(seq, 2 * v + 1, m + 1, r, max(m + 1, a), b, p);
    }
}

int Count(const vector<vector<ii>>& seq, int v, int l, int r, vector<node>& st, int n) {
    if (l == r)
        return l < n && Get(st[1]) <= 2;
    for (auto& [a, b] : seq[v])
        Add(st, 1, 0, 2 * n - 1, a, b, 1);
    int m = (l + r) / 2;
    int res = Count(seq, 2 * v, l, m, st, n) + Count(seq, 2 * v + 1, m + 1, r, st, n);
    for (auto& [a, b] : seq[v])
        Add(st, 1, 0, 2 * n - 1, a, b, -1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<ii>> seq(8 * n);
        vector<node> st(8 * n);
        vector<int> in(n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            in[a] = i;
        }
        Add(seq, 1, 0, 2 * n - 1, 0, in[1], {in[0], 2 * n - 1});
        Add(seq, 1, 0, 2 * n - 1, in[1] + 1, n + in[0], {n + in[0], 2 * n - 1});
        for (int i = 2; i <= n; i++)
            if (in[i - 1] < in[i])
                Add(seq, 1, 0, 2 * n - 1, in[i - 1] + 1, in[i], {in[i], 2 * n - 1});
            else {
                Add(seq, 1, 0, 2 * n - 1, 0, in[i], {in[i], in[i - 1] - 1});
                Add(seq, 1, 0, 2 * n - 1, in[i - 1] + 1, n + in[i], {n + in[i], n + in[i - 1] - 1});
            }
        cout << Count(seq, 1, 0, 2 * n - 1, st, n) << "\n";
    }
    return 0;
}
