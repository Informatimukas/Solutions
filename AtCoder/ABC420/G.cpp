#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin >> x;
    vector<ll> res;
    for (ll c = 1; c * c <= x; c++) {
        ll rem = x - c * c;
        if (rem % (2 * c - 1) == 0) {
            ll n = rem / (2 * c - 1);
            res.push_back(n);
        }
    }
    for (ll c = 0; c * c + c <= -x; c++) {
        ll rem = -x - c * c - c;
        if (rem % (2 * c + 1) == 0) {
            ll d = rem / (2 * c + 1);
            res.push_back(c + d);
        }
    }
    int lim = res.size();
    for (int i = 0; i < lim; i++)
        res.push_back(-res[i] - 1);
    ranges::sort(res);
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    return 0;
}