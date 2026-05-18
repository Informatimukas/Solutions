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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        vector<int> lsta(n + 2, n), lstb(n + 2, n);
        vector<ll> my(n + 1);
        ll res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == b[i]) {
                int na = lsta[a[i] + 1], nb = lstb[b[i] + 1];
                int ind = min(na, nb);
                my[i] = ind - i;
                if (na == nb)
                    my[i] += my[ind];
            }
            lsta[a[i]] = i;
            lstb[b[i]] = i;
            int na = lsta[1], nb = lstb[1];
            int ind = min(na, nb);
            res += ind - i;
            if (na == nb)
                res += my[ind];
        }
        cout << res << "\n";
    }
    return 0;
}
