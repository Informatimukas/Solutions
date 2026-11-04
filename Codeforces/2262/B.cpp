#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(vector<ll>& BIT, int x, ll val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] += val;
}

ll Get(const vector<ll>& BIT, int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> p(n);
        for (auto& x : p)
            cin >> x;
        vector<ll> BIT(n + 1);
        Add(BIT, p.back(), a[p.back()]);
        set<int> S;
        S.insert(p.back());
        vector<int> res(n);
        res[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            Add(BIT, p[i], a[p[i]]);
            S.insert(p[i]);
            auto it = S.find(p[i]);
            if (it != S.begin()) {
                --it;
                if (Get(BIT, *next(it) - 1) - Get(BIT, *it - 1) >= a[*next(it)])
                    S.erase(next(it));
                else ++it;
            }
            while (next(it) != S.end() && Get(BIT, *next(it) - 1) - Get(BIT, *it - 1) >= a[*next(it)])
                S.erase(next(it));
            res[i] = S.size() - 1;
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
