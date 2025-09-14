#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    ranges::sort(b);
    int best = m;
    for (int i = 0; i < n; i++) {
        int x = (b[i] - a[0] + m) % m;
        vector<int> cp = a;
        for (auto& y : cp)
            y = (y + x) % m;
        ranges::sort(cp);
        if (cp == b && x < best)
            best = x;
    }
    cout << best << "\n";
    return 0;
}