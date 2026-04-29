#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

void solveAll(vector<vector<int>>& B, set<int>& taken, vector<int>& res);

void solveCand(vector<vector<int>>& B, set<int>& taken, vector<int>& res,
    const vector<int>& cands) {
    int best = Inf;
    vector<int> wth;
    for (auto ind : cands) {
        while (!B[ind].empty() && taken.contains(B[ind].back()))
            B[ind].pop_back();
        if (B[ind].empty()) {
            solveAll(B, taken, res);
            return;
        }
        if (B[ind].back() < best) {
            best = B[ind].back();
            wth.clear();
        }
        if (B[ind].back() == best)
            wth.push_back(ind);
    }
    res.push_back(best);
    taken.insert(best);
    solveCand(B, taken, res, wth);
}

void solveAll(vector<vector<int>>& B, set<int>& taken, vector<int>& res) {
    int best = Inf;
    vector<int> wth;
    for (int ind = 0; ind < B.size(); ind++) {
        while (!B[ind].empty() && taken.contains(B[ind].back()))
            B[ind].pop_back();
        if (B[ind].empty())
            continue;
        if (B[ind].back() < best) {
            best = B[ind].back();
            wth.clear();
        }
        if (B[ind].back() == best)
            wth.push_back(ind);
    }
    if (best == Inf)
        return;
    res.push_back(best);
    taken.insert(best);
    solveCand(B, taken, res, wth);
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
        set<int> taken;
        vector<int> res;
        vector B(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            B[i].resize(l);
            for (auto& x : B[i])
                cin >> x;
        }
        solveAll(B, taken, res);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
