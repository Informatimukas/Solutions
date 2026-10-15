#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        priority_queue<lli, vector<lli>, greater<>> Q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i + 2 < n; i++)
            if ((a[i] % 2 != 0) == (a[i + 2] % 2 != 0))
                Q.emplace(a[i] + a[i + 2], i + 1);
        while (!Q.empty()) {
            int x = Q.top().second;
            Q.pop();
            ll cand = a[x - 1] + a[x + 1] - a[x];
            if (cand < a[x]) {
                a[x] = cand;
                if (x - 2 >= 0 && (a[x - 2] % 2 != 0) == (a[x] % 2 != 0))
                    Q.emplace(a[x - 2] + a[x], x - 1);
                if (x + 2 < n && (a[x] % 2 != 0) == (a[x + 2] % 2 != 0))
                    Q.emplace(a[x] + a[x + 2], x + 1);
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
