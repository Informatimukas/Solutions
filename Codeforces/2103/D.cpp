#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Write(vector<int>& res, const vector<int>& seq, int split, int cur, int delt) {
    auto ind = distance(seq.begin(), ranges::lower_bound(seq, split));
    for (int i = ind; i < seq.size(); i++) {
        res[seq[i]] = cur;
        cur += delt;
    }
    for (int i = ind - 1; i >= 0; i--) {
        res[seq[i]] = cur;
        cur += delt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), res(n, 0);
        vector seq(n + 1, vector<int>());
        vector<ii> wr(n + 1);
        int lst;
        for (auto& x : a)
            cin >> x;
        for (int i = 0; i < n; i++)
            if (a[i] == -1) lst = i;
            else seq[a[i]].push_back(i);
        int l = 1, r = n;
        int pnt = 1;
        while (!seq[pnt].empty()) {
            if (pnt % 2) {
                r -= seq[pnt].size();
                wr[pnt] = {r + 1, 1};
            } else {
                l += seq[pnt].size();
                wr[pnt] = {l - 1, -1};
            }
            pnt++;
        }
        int split = lst;
        for (int i = pnt - 1; i > 0; i--) {
            Write(res, seq[i], split, wr[i].first, wr[i].second);
            split = seq[i].back();
        }
        res[lst] = l;
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n? ' ': '\n');
    }
    return 0;
}