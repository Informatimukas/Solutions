#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

lli Xor(const lli& a, const lli& b) {
    return {a.first ^ b.first, a.second ^ b.second};
}

void Add(vector<lli>& BIT, int x, lli val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] = Xor(BIT[i],val);
}

lli Get(const vector<lli>& BIT, int x) {
    lli res = {0, 0};
    for (int i = x; i > 0; i -= i & -i)
        res = Xor(res, BIT[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector BIT(2 * n + 1, lli{0, 0});
        vector<ll> my(n);
        for (int i = 0; i < n; i++)
            my[i] = uniform_int_distribution<ll>(1, (1ll << 62ll) - 1)(rng);
        ll tot = 0;
        string res(n, '?');
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            lli got = Xor(Get(BIT, a), Get(BIT, b));
            got.second ^= 1;
            if (got.second)
                got.first ^= my[i];
            tot ^= got.first;
            res[i] = tot ? '0' : '1';
            Add(BIT, a, got);
            Add(BIT, b, got);
        }
        cout << res << "\n";
    }
    return 0;
}
