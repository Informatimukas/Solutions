#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Op(vector<int>&a, int ci, int cj, int x, vector<vector<int>>& res) {
    res.push_back({ci, cj, x});
    a[ci] -= x;
    a[cj] += x;
}

void Swap(vector<int>& a, int& ci, int cj, int ind, int k, vector<vector<int>>& res) {
    if (ci == ind) return;
    Op(a, ci, cj, k - a[ind] - a[ci], res);
    Op(a, ci, ind, a[ind] - a[ci], res);
    ci = ind;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> M;
        int ci = -1, cj = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (M.contains(k - a[i])) {
                ci = M[k - a[i]];
                cj = i;
            }
            M[a[i]] = i;
        }
        if (ranges::is_sorted(a)) {
            cout << "0\n";
            continue;
        }
        if (ci == -1) {
            cout << "-1\n";
            continue;
        }
        vector<vector<int>> res;
        Swap(a, ci, cj, 0, k, res);
        Swap(a, cj, ci, n - 1, k, res);
        vector<ii> seq;
        for (int i = 1; i < n - 1; i++)
            seq.emplace_back(a[i], i);
        ranges::sort(seq);

    }
    return 0;
}