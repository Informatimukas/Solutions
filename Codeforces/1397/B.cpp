#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

constexpr ld lim = 1e15l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    ll to = pow(lim, 1.0l / (n - 1));
    ll best = lim;
    for (ll i = 1; i <= to; i++) {
        ll cur = 1;
        ll cand = 0;
        for (int j = 0; j < n && cand < best; j++) {
            cand += abs(a[j] - cur);
            cur *= i;
        }
        best = min(best, cand);
    }
    cout << best << "\n";
    return 0;
}
