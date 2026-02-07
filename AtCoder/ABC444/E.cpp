#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool canInsert(const set<int>& S, int val, int d) {
    auto it = S.lower_bound(val);
    if (it != S.end() && *it - val < d)
        return false;
    if (it != S.begin()) {
        --it;
        if (val - *it < d)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    set<int> S;
    vector<int> a(n);
    ll res = 0;
    for (int r = 0, l = 0; r < n; r++) {
        cin >> a[r];
        while (!canInsert(S, a[r], d))
            S.erase(a[l++]);
        S.insert(a[r]);
        res += r - l + 1;
    }
    cout << res << "\n";
    return 0;
}
