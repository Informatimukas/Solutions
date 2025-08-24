#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cur += min(a[i], b[i]);
    }
    while (q--) {
        char ch;
        int x, v;
        cin >> ch >> x >> v;
        x--;
        cur -= min(a[x], b[x]);
        if (ch == 'A')
            a[x] = v;
        else b[x] = v;
        cur += min(a[x], b[x]);
        cout << cur << "\n";
    }
    return 0;
}