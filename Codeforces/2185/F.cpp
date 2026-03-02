#include <bits/stdc++.h>
using namespace std;

void Create(vector<int>& st, int v, int l, int r, const vector<int>& a) {
    if (l == r)
        st[v] = a[l];
    else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, a);
        Create(st, 2 * v + 1, m + 1, r, a);
        st[v] = st[2 * v] ^ st[2 * v + 1];
    }
}

int Solve(const vector<int>& st, int v, int l, int r, int x, int sw) {
    if (l == r) return 0;
    int res = 0;
    int m = (l + r) / 2;
    int A = st[2 * v], B = st[2 * v + 1];
    if (x <= m) {
        res += Solve(st, 2 * v, l, m, x, sw);
        A ^= sw;
        if (A < B)
            res += r - m;
    } else {
        res += Solve(st, 2 * v + 1, m + 1, r, x, sw);
        B ^= sw;
        if (A >= B)
            res += m + 1 - l;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        n = 1 << n;
        vector<int> a(n + 1);
        vector<int> st(4 * (n + 1));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Create(st, 1, 1, n, a);
        while (q--) {
            int b, c;
            cin >> b >> c;
            cout << Solve(st, 1, 1, n, b, c ^ a[b]) << "\n";
        }
    }
    return 0;
}
