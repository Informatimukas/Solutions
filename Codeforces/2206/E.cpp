#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lli = pair<ll, int>;

void addBIT(vector<ll>& BIT, int x, ll val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] += val;
}

ll getBIT(const vector<ll>& BIT, int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Update(int ind, int m, ll delt, vector<ll>& BIT, vector<deque<lli>>& my) {
    int myind = ind % m;
    auto& seq = my[myind];
    if (delt > 0) {
        addBIT(BIT, ind, delt);
        seq.emplace_front(delt, ind);
    } else
        while (delt < 0 && !seq.empty()) {
            int tk = min(-delt, seq.front().first);
            addBIT(BIT, seq.front().second, -tk);
            if (tk == seq.front().first)
                seq.pop_front();
            else seq.front().first -= tk;
            delt += tk;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int z = n - m + 2;
    vector<int> a(z);
    for (int i = 1; i < a.size(); i++)
        cin >> a[i];
    vector<vector<ii>> quer(n + 1);
    int q;
    cin >> q;
    vector<optional<ll>> res(q);
    for (int i = 0; i < q; i++) {
        int lef, rig;
        cin >> lef >> rig;
        quer[lef].emplace_back(rig, i);
    }
    vector BIT(n + 1, 0ll);
    vector<deque<lli>> my(m);
    for (int i = n; i > 0; i--) {
        if (i + 1 < z)
            Update(i + 1, m, a[i + 1] - a[i], BIT, my);
        for (auto [rig, ind] : quer[i]) {
            int s = rig - i + 1;
            if (s < m)
                continue;
            ll sum = a[i] + getBIT(BIT, rig - (m - 1));
            ll val = sum / m;
            if (sum > 0 && m * val < sum)
                val++;
            res[ind] = val;
        }
    }
    for (auto& x : res)
        if (x.has_value())
            cout << *x << "\n";
        else cout << "unbounded\n";
    return 0;
}
