#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<int> a(n + 1);
        vector<int> prefix, all;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i < p)
                prefix.push_back(a[i]);
            if (i != p)
                all.push_back(a[i]);
        }
        ranges::sort(prefix, greater());
        int cost = a[p];
        for (int i = k - 1; i < prefix.size(); i++)
            cost += prefix[i];
        if (cost > m) {
            cout << "0\n";
            continue;
        }
        m -= cost;
        cost = a[p];
        ranges::sort(all, greater());
        for (int i = k - 1; i < all.size(); i++)
            cost += all[i];
        cout << 1 + m / cost << "\n";
    }
    return 0;
}
