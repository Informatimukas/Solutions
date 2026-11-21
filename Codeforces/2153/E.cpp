#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 10000007;

int Solve(int n, int k) {
    int res = 0;
    while (k <= n) {
        n /= k;
        res += n;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxm);
    for (int i = 2; i < Maxm; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxm; j += i)
                mx[j] = i;
    vector<int> spec;
    for (int i = 2; i < Maxm; i++) {
        if (mx[i] == i)
            spec.push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        auto it = ranges::upper_bound(spec, m);
        int nxt = 1;
        ll res = 0;
        while (nxt < n && it != spec.begin()) {
            --it;
            cout << "it = " << *it << endl;
            
            while (nxt / *it != n / *it) {
                int nnxt = *it * (nxt / *it + 1);
                cout << "take " << Solve(nxt, *it, m) << " from " << nxt << " to " << nnxt << endl;
                res += static_cast<ll>(nnxt - nxt) * Solve(nxt, *it);
                nxt = nnxt;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
