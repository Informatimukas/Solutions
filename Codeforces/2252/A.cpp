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
        vector<int> cnt(1005);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
            res += a;
        }
        for (int i = 0; i < cnt.size(); i++)
            if (n - cnt[i] + 2 <= cnt[i])
                res -= i * (cnt[i] - (n - cnt[i] + 2));
        cout << res << "\n";
    }
    return 0;
}
