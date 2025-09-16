#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct MedianSet {
    multiset<int> small, middle, big;
    void moveMax(multiset<int>& a, multiset<int>& b) {
        b.insert(*a.rbegin());
        a.erase(prev(a.end()));
    }
    void moveMin(multiset<int>& a, multiset<int>& b) {
        b.insert(*a.begin());
        a.erase(a.begin());
    }
    void Fix() {
        if (small.size() > big.size())
            moveMax(small, middle);
        if (big.size() > small.size())
            moveMin(big, middle);
        if (middle.size() >= 3) {
            moveMin(middle, small);
            moveMax(middle, big);
        }
        if (middle.empty()) {
            moveMax(small, middle);
            moveMin(big, middle);
        }
    }
    void Insert(int x) {
        if (middle.empty())
            middle.insert(x);
        else if (x < *middle.begin())
            small.insert(x);
        else big.insert(x);
        Fix();
    }
    void Remove(int x) {
        if (middle.contains(x))
            middle.erase(middle.find(x));
        else if (small.contains(x))
            small.erase(small.find(x));
        else big.erase(big.find(x));
        Fix();
    }
    bool Has(int x) {
        return *middle.begin() <= x && x <= *middle.rbegin();
    }
};

optional<ii> Solve(int x, int k, const vector<int>& a, bool solveMax) {
    vector sum(a.size(), 0);
    ii best = {1000000000, 0};
    for (int i = 1; i < a.size(); i++) {
        sum[i] = sum[i - 1];
        if (solveMax)
            sum[i] += a[i] >= x ? 1 : -1;
        else sum[i] += a[i] <= x ? 1 : -1;
        if (i >= k)
            best = min(best, {sum[i - k], i - k});
        if (sum[i] >= best.first)
            return ii{best.second + 1, i};
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        array<int, 2> vals{};
        array<ii, 2> with;
        for (int solveMax = 0; solveMax < 2; solveMax++) {
            int lef = 1, rig = n;
            while (lef <= rig) {
                int m = lef + rig >> 1;
                auto got = Solve(m, k, a, solveMax);
                if (got) {
                    vals[solveMax] = m;
                    with[solveMax] = *got;
                    if (solveMax)
                        lef = m + 1;
                    else rig = m - 1;
                } else if (solveMax)
                    rig = m - 1;
                else lef = m + 1;
            }
        }
        vector<array<int, 3>> res;
        ii cur = with[0];
        int pnt = vals[0];
        MedianSet ms;
        for (int i = cur.first; i <= cur.second; i++)
            ms.Insert(a[i]);
        while (ms.Has(pnt))
            res.push_back({pnt++, cur.first, cur.second});
        while (cur.first > with[1].first) {
            ms.Insert(a[--cur.first]);
            while (ms.Has(pnt))
                res.push_back({pnt++, cur.first, cur.second});
        }
        while (cur.second < with[1].second) {
            ms.Insert(a[++cur.second]);
            while (ms.Has(pnt))
                res.push_back({pnt++, cur.first, cur.second});
        }
        while (cur.first < with[1].first) {
            ms.Remove(a[cur.first++]);
            while (ms.Has(pnt))
                res.push_back({pnt++, cur.first, cur.second});
        }
        while (cur.second > with[1].second) {
            ms.Remove(a[cur.second--]);
            while (ms.Has(pnt))
                res.push_back({pnt++, cur.first, cur.second});
        }
        cout << res.size() << "\n";
        for (auto& x : res)
            cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    }
    return 0;
}
