#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using ill = pair<int, ll>;

ill getStatus(const vector<int>& a) {
    ill res = {0, 0};
    for (auto& x : a)
        if (x) res.first++;
        else res.second += res.first;
    return res;
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        ill sta = getStatus(a);
        ill stb = getStatus(b);
        if (sta != stb) {
            cout << "No\n";
            continue;
        }
        array<vector<ii>, 2> res{};
        deque<int> A, B;
        for (int i = 0; i < n; i++) {
            A.push_back(i);
            B.push_back(i);
            if (a[A.back()] == b[B.front()]) {
                res[b[B.front()]].emplace_back(i + 1 - A.size(), i);
                A.pop_back();
                B.pop_front();
            }
            while (!A.empty() && a[A.front()] == b[B.front()]) {
                A.pop_front();
                B.pop_front();
            }
        }
        vector<array<int, 4>> ans;
        int i = 0, j = 0;
        while (i < res[0].size() && j < res[1].size()) {
            int lena = res[0][i].second - res[0][i].first;
            if (lena == 0) {
                i++;
                continue;
            }
            int lenb = res[1][j].second - res[1][j].first;
            if (lenb == 0) {
                j++;
                continue;
            }
            int tk = min(lena, lenb);
            ans.push_back({res[0][i].second - tk, res[0][i].second, res[1][j].second - tk, res[1][j].second});
            res[0][i].second -= tk;
            res[1][j].second -= tk;
        }
        cout << "Yes\n";
        assert(ans.size() <= n / 2);
        cout << ans.size() << "\n";
        for (auto& cur : ans) {
            if (cur[0] > cur[2]) {
                swap(cur[0], cur[2]);
                swap(cur[1], cur[3]);
            }
            cout<< cur[0] + 1 << " " << cur[1] + 1 << " " << cur[2] + 1 << " " << cur[3] + 1 << "\n";
        }
    }
    return 0;
}
