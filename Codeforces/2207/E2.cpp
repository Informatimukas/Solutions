#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

ll Solve(const vector<int>& a) {
    set forb(a.begin(), a.end());
    int cur = a.size();
    int pnt = cur;
    ll res = 1;
    set<int> rem, fre;
    for (int i = 0; i <= a.size(); i++) {
        rem.insert(i);
        if (!forb.contains(i))
            fre.insert(i);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > cur)
            return 0;
        if (a[i] == cur) {
            while (pnt >= 0 && forb.contains(pnt))
                pnt--;
            if (pnt < 0)
                return 0;
            res = res * static_cast<ll>(fre.size()) % mod;
            fre.erase(pnt);
            rem.erase(pnt--);
            continue;
        }
        rem.erase(cur);
        fre.erase(cur);
        res = res * static_cast<ll>(a.size() - fre.size()) % mod;
        cur = a[i];
        if (rem.empty() || *rem.rbegin() != a[i])
            return 0;
        pnt = min(pnt, a[i]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << Solve(a) << "\n";
    }
    return 0;
}
