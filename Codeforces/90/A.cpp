#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, Maxd> a;
    for (auto& x : a)
        cin >> x;
    int res = 0;
    while (ranges::count(a, 0) < Maxd) {
        res++;
        a[0] -= min(2, a[0]);
        ranges::rotate(a, a.begin() + 1);
    }
    cout << res + 30 - 1 << "\n";
    return 0;
}