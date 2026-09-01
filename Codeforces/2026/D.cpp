#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(ll x, const vector<ll>& a, const vector<ll>& sum, const vector<ll>& multsum,
    const vector<ll>& msum, const vector<ll>& seq) {
    auto s = distance(seq.begin(), ranges::upper_bound(seq, x)) - 1;
    ll res = msum[s];
    x -= seq[s];
    res += (x + s + 1) * (sum[s + x] - sum[s]) - (multsum[s + x] - multsum[s]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> sum(n + 1);
    vector<ll> multsum(n + 1);
    vector<ll> msum(n + 1);
    vector<ll> seq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        multsum[i] = multsum[i - 1] + i * a[i];
    }
    seq.push_back(0);
    for (int i = 1; i <= n; i++) {
        ll tims = (n + 1 - i);
        ll got = (tims + i) * (sum[n] - sum[i - 1]) - (multsum[n] - multsum[i - 1]);
        msum[i] = msum[i - 1] + got;
        ll nxt = seq.back() + (n + 1 - i);
        seq.push_back(nxt);
    }
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << Solve(r, a, sum, multsum, msum, seq) - Solve(l - 1, a, sum, multsum, msum, seq) << "\n";
    }
    return 0;
}
