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
        int n, k;
        cin >> n >> k;
        ll sum = 0;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }
        ranges::sort(a, greater());
        vector<int> b(k);
        for (auto& x : b)
            cin >> x;
        ranges::sort(b);
        int pnt = 0;
        for (auto& x : b)
            if (pnt + x <= a.size()) {
                sum -= a[pnt + x - 1];
                pnt += x;
            } else break;
        cout << sum << "\n";
    }
    return 0;
}
