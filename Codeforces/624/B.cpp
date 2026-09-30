#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a, greater());
    int cur = a[0];
    ll res = 0;
    for (auto x : a) {
        cur = min(cur, x);
        res += cur;
        cur = max(0, cur - 1);
    }
    cout << res << "\n";
    return 0;
}
