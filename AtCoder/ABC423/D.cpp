#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    queue<ii> Q;
    int rem = k;
    priority_queue<ii, vector<ii>, greater<>> leave;
    ll tim = 0;
    int pnt = 0;
    while (pnt < n || !leave.empty()) {
        tim = numeric_limits<ll>::max();
        if (pnt < n) tim = a[pnt];
        if (!leave.empty()) tim = min(tim, leave.top().first);
        while (!leave.empty() && leave.top().first <= tim) {
            rem += leave.top().second;
            leave.pop();
        }
        if (a[pnt] == tim) {
            Q.emplace(b[pnt], c[pnt]);
            pnt++;
        }
        while (!Q.empty() && Q.front().second <= rem) {
            cout << tim << "\n";
            rem -= Q.front().second;
            leave.emplace(tim + Q.front().first, Q.front().second);
            Q.pop();
        }
    }
    return 0;
}
