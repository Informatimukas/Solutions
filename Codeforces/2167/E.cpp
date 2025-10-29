#include <bits/stdc++.h>
using namespace std;

int Count(const vector<int>& a, int m, int dist) {
    int cur = 0, res = 0;
    for (auto& x : a) {
        if (cur <= x - dist)
            res += x - dist - cur + 1;
        cur = x + dist;
    }
    if (cur <= m)
        res += m - cur + 1;
    return res;
}

vector<int> Teleports(const vector<int>& a, int m, int dist, int k) {
    vector<int> res;
    int cur = 0;
    for (auto& x : a) {
        if (res.size() >= k)
            break;
        while (cur <= x - dist && res.size() < k)
            res.push_back(cur++);
        cur = x + max(1, dist);
    }
    while (cur <= m && res.size() < k)
        res.push_back(cur++);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        int lef = 1, rig = 1000000000;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Count(a, x, mid) >= k)
                lef = mid + 1;
            else rig = mid - 1;
        }
        auto res = Teleports(a, x, rig, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
