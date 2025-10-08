#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<int> Solve(int k) {
    vector<int> res;
    ii cur;
    map<ii, int> M = {{cur, 1}};
    int step = 1;
    while (k > 0) {
        ii nw;
        if (step == 1) {
            nw = {cur.first + 1, cur.second};
            if (M[nw] > k) {
                res.push_back(2);
                res.push_back(2);
                res.push_back(1);
                cur = {cur.first + 1, cur.second + 2};
                M.emplace(cur, 1);
                step = 1;
                continue;
            }
        } else if (step == 2) {
            nw = {cur.first, cur.second + 1};
            if (M[nw] > k) {
                res.push_back(1);
                res.push_back(2);
                cur = {cur.first + 1, cur.second + 1};
                M.emplace(cur, 1);
                step = 1;
                continue;
            }
        } else {
            nw = {cur.first - 1, cur.second - 1};
            if (M[nw] > k) {
                res.push_back(1);
                cur = {cur.first + 1, cur.second};
                M.emplace(cur, 1);
                step = 1;
                continue;
            }
        }
        res.push_back(step);
        k -= M[nw]++;
        cur = nw;
        step = step % 3 + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        auto res = Solve(k);
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
