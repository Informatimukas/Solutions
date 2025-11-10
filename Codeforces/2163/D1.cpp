#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ii> quer(q);
        for (auto& [a, b] : quer)
            cin >> a >> b;
        int m = (1 + n) / 2;
        int res = 0;
        if (Ask(1, m) > 0) {
            vector mx(n + 1, 0);
            for (auto& [l, r] : quer)
                if (l <= m)
                    mx[l] = max(mx[l], r);
            for (int i = 1; i <= n; i++)
                if (mx[i] > 0)
                    res = max(res, Ask(i, mx[i]));
        } else {
            vector mn(n + 1, n + 1);
            for (auto& [l, r] : quer)
                if (r > m)
                    mn[r] = min(mn[r], l);
            for (int i = 1; i <= n; i++)
                if (mn[i] <= n)
                    res = max(res, Ask(mn[i], i));
        }
        cout << "! " << res << endl;
    }
    return 0;
}
