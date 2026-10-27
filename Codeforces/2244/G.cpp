#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

void Add(map<int, ll>& M, int key, ll val) {
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        --it;
        if (it->second >= val)
            return;
        if (it->first < key)
            ++it;
    }
    while (it != M.end() && val >= it->second)
        M.erase(it++);
    M.emplace(key, val);
}

ll Get(map<int, ll>& M, int key) {
    auto it = M.lower_bound(key);
    if (it != M.begin()) {
        --it;
        return it->second;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        set<lli> S;
        vector<ll> res(n);
        map<int, ll> M;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            while (!S.empty() && S.begin()->first < i) {
                int ind = S.begin()->second;
                Add(M, ind, res[ind]);
                S.erase(S.begin());
            }
            res[i] = Get(M, i - a[i]) + a[i];
            ans = max(ans, res[i]);
            S.emplace(i + a[i], i);
        }
        cout << ans << "\n";
    }
    return 0;
}
