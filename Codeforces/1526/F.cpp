#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxq = 420;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

array<int, 3> Gen(int n) {
    array res = {1, 1, 1};
    while (res[0] == res[1] || res[0] == res[2] || res[1] == res[2])
        for (auto& el : res)
            el = uniform_int_distribution<int>(1, n)(rng);
    return res;
}

int Ask(const array<int, 3>& arr) {
    cout << "? " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    int res;
    cin >> res;
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
        int best = 1000000000, ba, bb;
        for (int i = 0; i < Maxq; i++) {
            auto arr = Gen(n);
            int cand = Ask(arr);
            if (cand < best) {
                best = cand;
                ba = arr[0];
                bb = arr[1];
            }
        }
        vector<ii> seq;
        for (int i = 1; i <= n; i++)
            if (i != ba && i != bb)
                seq.emplace_back(Ask({i, ba, bb}), i);
        seq.emplace_back(-1, ba);
        seq.emplace_back(-1, bb);
        ranges::sort(seq);
        vector<int> res(n + 1);
        int lef = 1, rig = n;
        res[lef++] = seq.back().second;
        int d = seq.back().first;
        seq.pop_back();
        int ind = seq.back().second;
        seq.pop_back();
        if (Ask({res[1], ind, ba}) == d - 1 ||
            Ask({res[1], ind, bb}) == d - 1)
            res[lef++] = ind;
        else {
            res[rig--] = ind;
            ind = seq.back().second;
            seq.pop_back();
            if (Ask({res[1], ind, ba}) == d - 1 ||
                Ask({res[1], ind, bb}) == d - 1)
                res[lef++] = ind;
            else res[rig--] = ind;
        }
        if (lef > 2) {
            while (!seq.empty()) {
                ind = seq.back().second;
                seq.pop_back();
                res[2 + Ask({res[1], res[2], ind})] = ind;
            }
        } else {
            while (!seq.empty()) {
                ind = seq.back().second;
                seq.pop_back();
                res[n - 1 - Ask({res[n], res[n - 1], ind})] = ind;
            }
        }
        vector<int> vals(n + 1);
        for (int i = 1; i <= n; i++)
            vals[res[i]] = i;
        if (vals[1] > vals[2])
            for (int i = 1; i <= n; i++)
                vals[i] = n + 1 - vals[i];
        cout << "!";
        for (int i = 1; i <= n; i++)
            cout << " " << vals[i];
        cout << endl;
        int tmp;
        cin >> tmp;
    }
    return 0;
}
