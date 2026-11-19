#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    array<ll, 2> cnt{}, to{};
    ll res{};
};

node Union(const node& a, const node& b) {
    node c;
    for (int i = 0; i < 2; i++) {
        c.cnt[i] = a.cnt[i] + b.cnt[i];
        c.to[i] = a.to[i] + b.to[i];
    }
    c.res = a.res + b.res + a.cnt[0] * b.to[1] + a.cnt[1] * b.to[0];
    return c;
}

void Create(vector<node>& st, int v, int l, int r, const string& s) {
    if (l == r) {
        int cur = s[l] == '1';
        st[v].cnt[cur] = 1;
        st[v].cnt[!cur] = 0;
        st[v].to[cur] = l > 0 && s[l - 1] != s[l] ? s.length() - l : 0;
        st[v].to[!cur] = 0;
        st[v].res = 0;
        return;
    }
    int m = (l + r) / 2;
    Create(st, 2 * v, l, m, s);
    Create(st, 2 * v + 1, m + 1, r, s);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

void Update(vector<node>& st, int v, int l, int r, int x, const string& s) {
    if (l == r) {
        int cur = s[l] == '1';
        st[v].cnt[cur] = 1;
        st[v].cnt[!cur] = 0;
        st[v].to[cur] = l > 0 && s[l - 1] != s[l] ? s.length() - l : 0;
        st[v].to[!cur] = 0;
        st[v].res = 0;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m)
        Update(st, 2 * v, l, m, x, s);
    else Update(st, 2 * v + 1, m + 1, r, x, s);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<node> st(4 * n);
        Create(st, 1, 0, n - 1, s);
        cout << st[1].res;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            s[x - 1] = s[x - 1] == '0' ? '1' : '0';
            Update(st, 1, 0, n - 1, x - 1, s);
            if (x < n)
                Update(st, 1, 0, n - 1, x, s);
            cout << " " << st[1].res;
        }
        cout << "\n";
    }
    return 0;
}
