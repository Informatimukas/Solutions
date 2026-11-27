#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector cnt(Maxn, vector<int>(Maxn));
    vector<int> all(Maxn);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        all[b]++;
        cnt[a][b]++;
    }
    int res1 = 0, res2 = 0;
    vector<int> rem;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (cnt[a][b] > 0) {
            res1++; res2++;
            cnt[a][b]--;
            all[b]--;
        } else rem.push_back(b);
    }
    for (auto x : rem)
        if (all[x] > 0) {
            all[x]--;
            res1++;
        }
    cout << res1 << " " << res2 << "\n";
    return 0;
}
