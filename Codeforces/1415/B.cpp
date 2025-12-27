#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (auto& x : c)
            cin >> x;
        int res = n;
        for (int i = 1; i <= 100; i++) {
            int from = 0, cand = 0;
            for (int j = 0; j < n; j++)
                if (c[j] != i && from <= j) {
                    from = j + k;
                    ++cand;
                }
            res = min(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
