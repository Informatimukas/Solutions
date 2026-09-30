#include <bits/stdc++.h>
using namespace std;

struct node {
    int delt{0};
    int mn{0};
};

void Create(vector<node>& st, int v, int l, int r) {
    if (l == r)
        st[v].mn = -(l + 1);
    else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
        st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
    }
}

void downOn(vector<node>& st, int v, int fl) {
    st[v].delt += fl;
    st[v].mn += fl;
}

void Down(vector<node>& st, int v) {
    if (st[v].delt) {
        downOn(st, 2 * v, st[v].delt);
        downOn(st, 2 * v + 1, st[v].delt);
        st[v].delt = 0;
    }
}

void Update(vector<node>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        downOn(st, v, delt);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
    }
}

int Solve(vector<node>& st, int v, int l, int r) {
    if (st[v].mn >= 0)
        return r + 1;
    if (l == r)
        return l;
    Down(st, v);
    int m = (l + r) / 2;
    int res = Solve(st, 2 * v, l, m);
    if (res <= m)
        return res;
    return Solve(st, 2 * v + 1, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<node> st(4 * (n + 1));
    Create(st, 1, 0, n);
    vector<int> seq(n + 1);
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        seq[i] = max(0, a[i] - A) + max(0, b[i] - B);
        if (seq[i] <= n)
            Update(st, 1, 0, n, seq[i], n, 1);
    }
    int m;
    cin >> m;
    while (m--) {
        int k, na, nb;
        cin >> k >> na >> nb;
        if (seq[k] <= n)
            Update(st, 1, 0, n, seq[k], n, -1);
        seq[k] = max(0, na - A) + max(0, nb - B);
        if (seq[k] <= n)
            Update(st, 1, 0, n, seq[k], n, 1);
        cout << Solve(st, 1, 0, n) << "\n";
    }
    return 0;
}
