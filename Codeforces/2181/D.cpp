#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1000000000;

void Update(vector<int>& st, int v, int l, int r, int a, int b, int val) {
    if (l == a && r == b)
        st[v] = min(st[v], val);
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}

int Get(const vector<int>& st, int v, int l, int r, int mn, const vector<int>& un) {
    mn = min(mn, st[v]);
    if (l == r)
        return mn - un[l];
    int m = (l + r) / 2;
    return max(Get(st, 2 * v, l, m, mn, un), Get(st, 2 * v + 1, m + 1, r, mn, un));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> seq;
    vector<int> un;
    while (n--) {
        int k, x1, x2;
        cin >> k >> x1 >> x2;
        int rig = x2;
        vector<int> a(k);
        for (auto& x : a) {
            cin >> x;
            rig -= x;
        }
        int lef = x1;
        seq.push_back({0, lef, 0});
        for (auto x : a) {
            seq.push_back({lef, lef + x, rig});
            lef += x;
            rig += x;
        }
        seq.push_back({lef, rig, rig});
        seq.push_back({rig, lim, 0});
    }
    for (auto& arr : seq) {
        un.push_back(arr[0]);
        un.push_back(arr[1]);
    }
    ranges::sort(un);
    un.erase(ranges::unique(un).begin(), un.end());
    vector st(4 * un.size(), lim);
    for (auto& arr : seq) {
        int lef = distance(un.begin(), ranges::lower_bound(un, arr[0]));
        int rig = distance(un.begin(), ranges::lower_bound(un, arr[1]));
        if (lef == rig)
            continue;
        Update(st, 1, 0, un.size() - 1, lef, rig - 1, arr[2]);
    }
    cout << Get(st, 1, 0, un.size() - 1, lim, un) << "\n";
    return 0;
}