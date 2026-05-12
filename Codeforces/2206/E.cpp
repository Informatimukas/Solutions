#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lli = pair<ll, int>;

struct pos {
    deque<lli> seq;
    ll zer{0};
};

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

void Update(int ind, int m, ll delt, vector<ll>& BIT, vector<pos>& my) {
    int myind = ind % m;
    auto& p = my[myind];
    if (delt >= 0) {
        addBIT(BIT, )
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int z = n - m + 1;
    vector<int> a(z);
    for (auto& x : a)
        cin >> x;
    vector<vector<ii>> quer(n + 1);
    int q;
    cin >> q;
    vector<ll> res(q);
    for (int i = 0; i < q; i++) {
        int lef, rig;
        cin >> lef >> rig;
        quer[lef].emplace_back(rig, i);
    }
    vector BIT(n + 1, 0ll);
    vector<pos> my(m);
    for (int i = n; i > 0; i--) {

    }
    return 0;
}
