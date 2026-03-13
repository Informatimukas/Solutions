#include <bits/stdc++.h>
using namespace std;

void Create(vector<int>& st, const vector<int>& a, int v, int l, int r) {
    if (l == r)
        st[v] = a[l];
    else {
        int m = (l + r) / 2;
        Create(st, a, 2 * v, l, m);
        Create(st, a, 2 * v + 1, m + 1, r);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<int>& st, vector<int>& a, int v, int l, int r, int x) {
    if (l == r)
        st[v] = a[l];
    else {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, a, 2 * v, l, m, x);
        else Update(st, a, 2 * v + 1, m + 1, r, x);
        st[v] = min(st[2 * v], st[2 * v + 1]);
    }
}

int getMin(const vector<int>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v];
    int m = (l + r) / 2;
    int res = 1000000000;
    if (a <= m)
        res = min(res, getMin(st, 2 * v, l, m, a, min(m, b)));
    if (m + 1 <= b)
        res = min(res, getMin(st, 2 * v + 1, m + 1, r, max(m + 1, a), b));
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> st(4 * n);
        Create(st, a, 1, 1, n);
        while (q--) {
            int typ;
            cin >> typ;
            if (typ == 1) {
                int ind, val;
                cin >> ind >> val;
                a[ind] = val;
                Update(st, a, 1, 1, n, ind);
            } else {
                int l, r;
                cin >> l >> r;
                int lef = 0, rig = r - l;
                int res = 0;
                while (lef <= rig) {
                    int mid = (lef + rig) / 2;
                    int got = getMin(st, 1, 1, n, l, l + mid);
                    if (mid > got)
                        rig = mid - 1;
                    else if (mid < got)
                        lef = mid + 1;
                    else {
                        res = 1;
                        break;
                    }
                }
                cout << res << "\n";
            }
        }
    }
    return 0;
}
