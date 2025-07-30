#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxk = 20;
constexpr int Inf = 1000000000;

ii getMax(const vector<vector<ii>>& mx, int l, int r) {
    ii res = {-1, -1};
    for (int i = Maxk - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

ii Get(const vector<vector<ii>>& mx, int l, int r) {
    int m = getMax(mx, l, r).second;
    if (m == -1) { return {0, 0}; }
    ii gotLef = Get(mx, l, m - 1);
    ii gotRig = Get(mx, m + 1, r);
    return {1 + max(gotLef.first, gotRig.first),
        max(1 + gotLef.first + gotRig.first, 1 + max(gotLef.second, gotRig.second))};
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector mx(n, vector(Maxk, ii{0, 0}));
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
            mx[i][0] = {p[i], i};
        }
        string s; cin >> s;
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i + (1 << j) <= n; i++)
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
        int ind = distance(p.begin(), ranges::max_element(p));
        deque D = {ind};
        for (int i = ind + 1; i < n; i++) {
            while (p[i] > p[D.back()])
                D.pop_back();
            D.push_back(i);
        }
        for (int i = ind - 1; i >= 0; i--) {
            while (p[i] > p[D.front()])
                D.pop_front();
            D.push_front(i);
        }
        int pref = -Inf, res = -Inf;
        for (int i = 0; i + 1 < D.size(); i++) {
            ii got = Get(mx, D[i] + 1, D[i + 1] - 1);
            res = max(res, 1 + got.second);
            res = max(res, pref + i + 1 + got.first);
            pref = max(pref, -i + got.first);
        }
        cout << res << '\n';
    }
    return 0;
}
