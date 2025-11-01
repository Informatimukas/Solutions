#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 2000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M = {{0, Inf}};
    ll cur = Inf;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = M.upper_bound(a);
        int my = Inf;
        if (it != M.end()) {
            int dist = it->first - a;
            my = dist;
            if (dist < it->second) {
                cur += dist - it->second;
                it->second = dist;
            }
        }
        --it;
        int d = a - it->first;
        my = min(my, d);
        if (d < it->second) {
            cur += d - it->second;
            it->second = d;
        }
        M.emplace(a, my);
        cur += my;
        cout << cur << "\n";
    }
    return 0;
}