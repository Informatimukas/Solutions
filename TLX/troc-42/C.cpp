#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    ll lefx = x, rigx = x, lefy = y, rigy = y;
    ll res = 0;
    while (m--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            ll tk = 0;
            if (k < lefx) tk = lefx - k;
            else if (rigx < k) tk = k - rigx;
            lefy -= tk;
            rigy += tk;
            lefx = rigx = k;
            res += tk;
        } else {
            ll tk = 0;
            if (k < lefy) tk = lefy - k;
            else if (k > rigy) tk = k - rigy;
            lefx -= tk;
            rigx += tk;
            lefy = rigy = k;
            res += tk;
        }
    }
    cout << res << "\n";
    return 0;
}