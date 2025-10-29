#include <bits/stdc++.h>
using namespace std;

array<int, 2> Traverse(int v, int p, const vector<vector<int>>& neigh) {
    array<int, 2> res{};
    int flexible = 0;
    int cur = 0;
    vector<int> seq;
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        auto got = Traverse(u, v, neigh);
        flexible += max(got[0], got[1]);
        cur += got[0];
        seq.push_back(got[1] - got[0]);
    }
    ranges::sort(seq, greater());
    int my = neigh[v].size() / 2;
    for (int i = 0; i < 2; i++) {
        res[i] = flexible;
        int nd = my - (i == 0);
        if (nd < 0 || nd > seq.size())
            continue;
        int cand = cur;
        for (int j = 0; j < nd; j++)
            cand += seq[j];
        res[i] = max(res[i], cand + 1);
    }
    return res;
}

int Solve(const vector<vector<int>>& neigh) {
    int flexible = 0;
    int cur = 0;
    vector<int> seq;
    for (auto& u : neigh[1]) {
        auto got = Traverse(u, 1, neigh);
        flexible += max(got[0], got[1]);
        cur += got[0];
        seq.push_back(got[1] - got[0]);
    }
    ranges::sort(seq, greater());
    int my = neigh[1].size() / 2;
    int res = flexible;
    if (my < 0 || my > seq.size())
        return res;
    int cand = cur;
    for (int i = 0; i < my; i++)
        cand += seq[i];
    res = max(res, cand + 1);
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
        vector neigh(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
            neigh[i].push_back(p);
        }
        cout << Solve(neigh) << "\n";
    }
    return 0;
}
