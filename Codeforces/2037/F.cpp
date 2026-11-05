#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr int lim = 1000000007;

bool Solve(int m, int k, int tims, const vector<int>& h, const vector<int>& x) {
    vector<lli> seq;
    for (int i = 0; i < x.size(); i++) {
        ll lef = 0, rig = m;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            if (tims * (m - mid) >= h[i])
                lef = mid + 1;
            else rig = mid - 1;
        }
        if (rig >= 0) {
            seq.emplace_back(x[i] - rig, 1);
            seq.emplace_back(x[i] + rig + 1, -1);
        }
    }
    ranges::sort(seq);
    int st = 0;
    for (auto z : seq | views::values) {
        st += z;
        if (st >= k)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> h(n);
        for (auto& x : h)
            cin >> x;
        vector<int> x(n);
        for (auto& z : x)
            cin >> z;
        int lef = 1, rig = lim;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Solve(m, k, mid, h, x))
                rig = mid - 1;
            else lef = mid + 1;
        }
        if (lef >= lim)
            lef = -1;
        cout << lef << "\n";
    }
    return 0;
}
