#include <bits/stdc++.h>
using namespace std;

struct node {
    int mx{0};
    int flag{0};
};

void downOn(vector<node>& st, int v, int val) {
    st[v].mx += val;
    st[v].flag += val;
}

void Down(vector<node>& st, int v) {
    if (st[v].flag) {
        downOn(st, 2 * v, st[v].flag);
        downOn(st, 2 * v + 1, st[v].flag);
        st[v].flag = 0;
    }
}

void Update(vector<node>& st, int v, int l, int r, int x) {
    if (l == r)
        st[v].mx = 0;
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, 2 * v, l, m, x);
        else {
            downOn(st, 2 * v, 1);
            Update(st, 2 * v + 1, m + 1, r, x);
        }
        st[v].mx = max(st[2 * v].mx, st[2 * v + 1].mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<node> st(4 * (n + 1));
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            Update(st, 1, 0, n, a);
            cout << st[1].mx << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
