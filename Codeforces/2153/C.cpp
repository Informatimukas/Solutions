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
        map<ll, int> M;
        set<ll> S;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            M[a]++;
        }
        int cnt = 0;
        ll sum = 0;
        for (auto& [key, c] : M) {
            cnt += c / 2 * 2;
            sum += c / 2 * 2 * key;
            if (c % 2)
                S.insert(key);
        }
        ll best = 0;
        if (cnt > 2)
            best = max(best, sum);
        for (auto& x : S) {
            if (cnt + 1 > 2 && x < sum)
                best = max(best, sum + x);
            auto it = S.lower_bound(sum + x);
            if (it != S.begin()) {
                --it;
                if (cnt + 2 > 2 && x < *it)
                    best = max(best, sum + x + *it);
            }
        }
        cout << best << "\n";
    }
    return 0;
}
