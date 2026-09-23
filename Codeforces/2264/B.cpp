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
        int n, m;
        cin >> n >> m;
        priority_queue<ll> Q;
        ll sum = 0, res = -1000000000000000000ll;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            if (Q.size() == m - 1)
                res = max(res, m * a - sum);
            Q.push(a);
            sum += a;
            if (Q.size() >= m) {
                sum -= Q.top();
                Q.pop();
            }
        }
        cout << res << "\n";
    }
    return 0;
}
