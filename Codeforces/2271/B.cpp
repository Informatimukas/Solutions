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
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int pnt = 0;
        while (pnt <= n && cnt[pnt] >= 2 * k)
            pnt++;
        bool ok = pnt <= n && cnt[pnt] == k + k - 1;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
