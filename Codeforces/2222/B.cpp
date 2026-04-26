#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        array<vector<int>, 2> seq{};
        array<int, 2> cnt{};
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            seq[i % 2].push_back(a);
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            cnt[a % 2]++;
        }
        ll res = 0;
        for (int z = 0; z < 2; z++)
            if (cnt[z] == 0) {
                for (auto x : seq[z])
                    res += x;
            } else {
                ranges::sort(seq[z]);
                int lft = max(0, static_cast<int>(seq[z].size()) - cnt[z]);
                for (int i = 0; i < lft; i++)
                    res += seq[z][i];
                for (int i = lft; i + 1 < seq[z].size(); i++)
                    res += min(seq[z][i], 0);
            }
        cout << res << "\n";
    }
    return 0;
}
