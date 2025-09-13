#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(const vector<int>& a, int k) {
    vector cnt(a.size() + 1, 0);
    for (auto& x : a)
        cnt[x]++;
    for (int i = 1; i <= a.size(); i++) {
        if (cnt[i] % k)
            return 0;
        cnt[i] /= k;
    }
    ll res = 0;
    int bad = 0;
    for (int i = 0, lef = 0; i < a.size(); i++) {
        if (cnt[a[i]]-- == 0)
            bad++;
        while (bad > 0) {
            if (++cnt[a[lef]] == 0)
                bad--;
            lef++;
        }
        res += i - lef + 1;
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << Solve(a, k) << "\n";
    }
    return 0;
}
