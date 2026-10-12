#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mn = 0, sum = 0;
    ll h;
    int n;
    cin >> h >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h += a[i];
        if (h <= 0) {
            cout << i + 1 << "\n";
            return 0;
        }
        sum += a[i];
        mn = min(mn, sum);
    }
    if (sum >= 0) {
        cout << "-1\n";
        return 0;
    }
    ll res = n;
    ll tims = max(0ll, (h + mn) / -sum);
    h += sum * tims;
    res += n * tims;
    while (true) {
        for (int i = 0; i < n; i++) {
            res++;
            h += a[i];
            if (h <= 0) {
                cout << res << "\n";
                return 0;
            }
        }
    }
    return 0;
}
