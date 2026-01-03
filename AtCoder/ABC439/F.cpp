#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

void Add(vector<ll>& BIT, int x, ll val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] = (BIT[i] + val) % mod;
}

ll Get(const vector<ll>& BIT, int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll res = 0;
    vector ones(n + 1, 0ll);
    vector seq(n + 1, 0ll);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ll all = Get(seq, n);
        ll lef = Get(seq, a);
        ll rig = (all - lef + mod) % mod;
        ll up = (Get(ones, a) + lef) % mod;
        ll down = rig;
        res = (res + down) % mod;
        ll val = (up + down) % mod;
        Add(ones, a, 1);
        Add(seq, a, val);
    }
    cout << res << "\n";
    return 0;
}
