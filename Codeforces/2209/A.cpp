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
        ll c, k;
        cin >> n >> c >> k;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        for (auto x : a)
            if (x <= c) {
                ll tk = min(k, c - x);
                k -= tk;
                x += tk;
                c += x;
            }
        cout << c << "\n";
    }
    return 0;
}
