#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector dpm(2 * n, -Inf), dp1(2 * n, -Inf);
        int global = -Inf;
        vector one(n, -Inf);
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        if (m == 1) {
            cout << "0\n";
            continue;
        }
        priority_queue<ii> Q;
        dpm[n - 1] = a[n - 1] == m;
        Q.emplace(dpm[n - 1], n - 1);
        for (int i = n - 2; i >= 0; i--) {
            // write m
            int cost = one[i + 1];
            while (!Q.empty() && Q.top().second > i + m)
                Q.pop();
            if (!Q.empty())
                cost = max(cost, Q.top().first);
            cost += a[i] == m;
            dpm[i] = max(dpm[i], cost);
            Q.emplace(dpm[i], i);
            // write same
            if (a[i] != 1 && a[i] != m) {
                int val = max({dpm[i - a[i] + m], global, dp1[i - a[i] + m]}) + 1;
                dpm[i - a[i] + m] = val;
                Q.emplace(dpm[i - a[i] + m], i - a[i] + m);
                dp1[i - a[i] + m] = val;
            }
            // write 1
            one[i] = max({dp1[i + m - 1], dpm[i + m - 1], global}) + (a[i] == 1);
            global = max(global, one[i]);
        }
        cout << n - one[0] << "\n";
    }
    return 0;
}
