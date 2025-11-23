#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mod;
    cin >> n >> mod;
    vector<ll> pw10(11);
    pw10[0] = 1;
    for (int i = 1; i < pw10.size(); i++)
        pw10[i] = 10ll * pw10[i - 1];
    vector by10(pw10.size(), vector<int>());
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int ind = distance(pw10.begin(), ranges::upper_bound(pw10, a[i]));
        by10[ind].push_back(a[i]);
    }
    ll res = 0;
    for (int i = 1; i < pw10.size(); i++) {
        ll mult = pw10[i] % mod;
        map<int, int> M;
        for (auto& x : a)
            ++M[mult * x % mod];
        for (auto& x : by10[i]) {
            int nd = (mod - x % mod) % mod;
            res += M[nd];
        }
    }
    cout << res << "\n";
    return 0;
}