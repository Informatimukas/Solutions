#include <bits/stdc++.h>
using namespace std;

using ib = pair<int, bool>;
using ll = long long;

constexpr int Inf = 1000000000;

ib Solve(const vector<int>& a, vector<int>& b, int x) {
    array mx = {0, 0};
    mx[0] = b[0] = x;
    for (int i = 1; i < a.size(); i++) {
        b[i] = a[i] - b[i - 1];
        if (b[i] < 0)
            return i % 2 ? ib{Inf, false} : ib{Inf, true};
        mx[i % 2] = max(mx[i % 2], b[i]);
    }
    if (mx[0] >= mx[1])
        return {mx[0], false};
    return {mx[1], true};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        ll sum = 0;
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }
        int lef = 0, rig = a[0];
        int best = Inf;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            auto [mx, rec] = Solve(a, b, mid);
            if (mx < best)
                best = mx;
            if (rec)
                lef = mid + 1;
            else rig = mid - 1;
        }

    }
    return 0;
}
