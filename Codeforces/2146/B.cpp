#include <bits/stdc++.h>
using namespace std;

bool Solve(const vector<int>& cnt, const vector<vector<int>>& seq) {
    for (int i = 1; i < cnt.size(); i++)
        if (cnt[i] == 0)
            return false;
    int res = 0;
    for (auto& V : seq) {
        bool good = true;
        for (auto& x : V)
            if (cnt[x] == 1) {
                good = false;
                break;
            }
        if (good)
            res++;
    }
    return res >= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector cnt(m + 1, 0);
        vector seq(n, vector<int>());
        for (auto& V : seq) {
            int k;
            cin >> k;
            V.resize(k);
            for (auto& x : V) {
                cin >> x;
                cnt[x]++;
            }
        }
        cout << (Solve(cnt, seq) ? "YES" : "NO") << "\n";
    }
    return 0;
}
