#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void SwapC(vector<int>& c, int p, int q, ll& cnt) {
    set<int> S;
    for (auto& el : {p, q}) {
        if (el > 1)
            S.insert(el - 1);
        if (el + 1 < c.size())
            S.insert(el);
    }
    for (auto& el : S)
        if (c[el] > c[el + 1])
            cnt--;
    swap(c[p], c[q]);
    for (auto& el : S)
        if (c[el] > c[el + 1])
            cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1), ina(n + 1), b(n + 1), inb(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ina[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        inb[b[i]] = i;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = ina[b[i]];
        if (i >= 2 && c[i - 1] > c[i])
            cnt++;
    }
    cout << (cnt - 1) * n + c[n] << "\n";
    for (int i = 0; i < d - 1; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            swap(a[x], a[y]);
            ina[a[x]] = x;
            ina[a[y]] = y;
            SwapC(c, inb[a[x]], inb[a[y]], cnt);
        } else {
            swap(b[x], b[y]);
            inb[b[x]] = x;
            inb[b[y]] = y;
            SwapC(c, inb[b[x]], inb[b[y]], cnt);
        }
        cout << (cnt - 1) * n + c[n] << "\n";
    }
    return 0;
}
