#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector dvs(n + 1, vector<int>());
        for (int i = 2; i <= n; i++)
            for (int j = i; j <= n; j += i)
                dvs[j].push_back(i);
        vector cnt(n + 1, 0);
        int g;
        cin >> g;
        cout << "0";
        int res = 0;
        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;
            int ng = __gcd(g, a);
            if (g > ng) {
                res = i;
                for (auto& d : dvs[g / ng])
                    cnt[d] = i;
            }
            for (auto& d : dvs[a / ng]) {
                cnt[d]++;
                res = max(res, cnt[d]);
            }
            g = ng;
            cout << " " << res;
        }
        cout << "\n";
    }
    return 0;
}