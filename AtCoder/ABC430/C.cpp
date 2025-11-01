#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector asum(n + 1, 0), bsum(n + 1, 0);
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        asum[i] = asum[i - 1] + (s[i - 1] == 'a');
        bsum[i] = bsum[i - 1] + (s[i - 1] == 'b');
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        auto lef = distance(asum.begin(), ranges::partition_point(asum, [&,y=asum[i]](auto&& x) {
            return x - y < a;
        }));
        auto rig = distance(bsum.begin(), ranges::partition_point(bsum, [&,y=bsum[i]](auto&& x) {
            return x - y < b;
        }));
        if (lef < rig)
            res += rig - lef;
    }
    cout << res << "\n";
    return 0;
}