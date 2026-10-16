#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& num : x)
        cin >> num;
    vector<int> v(n);
    for (auto& num : v)
        cin >> num;
    ld lef = 1, rig = 1000000000;
    ld res = 1e18l;
    for (int i = 0; i < 60; i++) {
        ld mid = (lef + rig) / 2;
        ld tp = 0, bot = 0;
        for (int j = 0; j < n; j++)
            if (x[j] <= mid)
                bot = max(bot, (mid - x[j]) / v[j]);
            else tp = max(tp, (x[j] - mid)/ v[j]);
        res = min(res, max(bot, tp));
        if (bot > tp)
            rig = mid;
        else lef = mid;
    }
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}
