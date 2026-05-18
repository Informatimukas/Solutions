#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxn = 1000005;
constexpr int Inf = 1000000000;

void Solve(vector<ii>& pc, const vector<int>& tp, const vector<int>& tc, const vector<int>& d,
    vector<int>& res) {
    ranges::sort(pc, {}, [](auto&& x) { return x.second; });
    vector<int> seq(d.size());
    iota(seq.begin(), seq.end(), 0);
    ranges::sort(seq, {}, [&](auto&& x) { return tc[x]; });
    int val = Inf;
    int pnt = 0;
    for (auto ind : seq) {
        while (pnt < pc.size() && pc[pnt].second < tc[ind])
            val = min(val, pc[pnt++].first);
        if (pnt == 0)
            continue;
        if (val < tp[ind])
            res[ind] = 0;
        else if (val < tp[ind] + d[ind])
            res[ind] = min(res[ind], val);
        else res[ind] = min(res[ind], tp[ind] + d[ind]);
    }
    ranges::reverse(pc);
    ranges::sort(seq, greater(), [&](auto&& x) { return tc[x] + d[x]; });
    val = Inf;
    pnt = 0;
    for (auto ind : seq) {
        while (pnt < pc.size() && pc[pnt].second >= tc[ind] + d[ind])
            val = min(val, pc[pnt++].first);
        if (pnt == 0)
            continue;
        if (val < tp[ind])
            res[ind] = min(res[ind], tc[ind] + d[ind]);
        else if (val < tp[ind] + d[ind])
            res[ind] = min(res[ind], tc[ind] + d[ind] + val);
        else res[ind] = min(res[ind], tc[ind] + d[ind] + tp[ind] + d[ind]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int gmin = Inf;
    vector<ii> pc(n);
    for (int i = 0; i < n; i++)
        cin >> pc[i].first;
    for (int i = 0; i < n; i++) {
        cin >> pc[i].second;
        gmin = min(gmin, pc[i].first + pc[i].second);
    }
    int m;
    cin >> m;
    vector<int> tp(m), tc(m), d(m), res(m, gmin);
    for (auto& x : tp)
        cin >> x;
    for (auto& x : tc)
        cin >> x;
    for (auto& x : d)
        cin >> x;
    Solve(pc, tp, tc, d, res);
    for (auto& x : pc)
        swap(x.first, x.second);
    for (int i = 0; i < m; i++)
        swap(tp[i], tc[i]);
    Solve(pc, tp, tc, d, res);
    for (auto x : res)
        cout << x << "\n";
    return 0;
}
