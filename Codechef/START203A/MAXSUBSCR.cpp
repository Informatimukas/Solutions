#include <bits/stdc++.h>
using namespace std;

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
        vector pnt(n + 1, 0);
        vector seq(n + 1, vector<int>());
        for (auto& x : a)
            cin >> x;
        int res = 0;
        set<int> S;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = pnt[a[i]]; j < seq[a[i]].size(); j++) {
                if (S.empty() || *S.rbegin() < seq[a[i]][j]) {
                    pnt[a[i]] = j + 1;
                    continue;
                }
                S.erase(S.lower_bound(seq[a[i]][j]));
            }
            S.insert(i);
            seq[a[i]].push_back(i);
            res = max(res, static_cast<int>(S.size()));
        }
        cout << res << "\n";
    }
    return 0;
}
