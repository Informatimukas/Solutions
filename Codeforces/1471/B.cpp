#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<ii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = 1;
        }
        for (int i = 0; i < a.size(); i++)
            if (a[i].first % x == 0)
                a.emplace_back(a[i].first / x, a[i].second * x);
            else break;
        cout << accumulate(a.begin(), a.end(), 0ll, [](ll x, const ii& p) {
            return x + p.first * p.second;
        }) << '\n';
    }
    return 0;
}
