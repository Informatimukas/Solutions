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
        for (auto& x : a)
            cin >> x;
        for (int i = 0; i < n; i++) {
            vector<int> seq(n);
            int cur = 0;
            for (int j = 1; j < n; j++) {
                int p = (i - j + n) % n;
                cur = max(cur, a[p]);
                seq[p] = cur;
            }
            cur = a[i];
            for (int j = 1; j < n; j++) {
                int p = (i + j) % n;
                seq[p] = min(seq[p], cur);
                cur = max(cur, a[p]);
            }
            cout << accumulate(seq.begin(), seq.end(), 0ll) << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
