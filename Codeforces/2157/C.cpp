#include <bits/stdc++.h>
using namespace std;

constexpr int Maxp = 3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<array<int, Maxp>> queries(q);
        for (auto& arr : queries)
            for (auto& x : arr)
                cin >> x;
        vector<int> a(n + 1);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            array<bool, 3> was{};
            for (auto& x : queries)
                if (x[1] <= i && i <= x[2])
                    was[x[0]] = true;
            if (was[1] && was[2])
                a[i] = k + 1;
            else if (was[1])
                a[i] = k;
            else if (was[2]) {
                a[i] = cur;
                cur = (cur + 1) % k;
            } else a[i] = k;
            cout << a[i] << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
