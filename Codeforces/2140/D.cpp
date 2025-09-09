#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ii> seq;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            sum += r - l;
            sum += r;
            seq.emplace_back(l + r, r);
        }
        ranges::sort(seq);
        for (int i = 0; i < n / 2; i++)
            sum -= seq[i].first;
        if (n % 2 == 0) {
            cout << sum << "\n";
            continue;
        }
        ll mx = 0;
        for (int i = 0; i < n; i++)
            if (i < n / 2) {
                int l = seq[i].first - seq[i].second;
                mx = max(mx, sum + l - seq[n / 2].first);
            } else {
                int r = seq[i].second;
                mx = max(mx, sum - r);
            }
        cout << mx << "\n";
    }
    return 0;
}