#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> odd;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2) odd.push_back(a);
            else res += a;
        }
        if (odd.empty()) {
            cout << "0\n";
            continue;
        }
        ranges::sort(odd, greater());
        int uses = (odd.size() + 1) / 2;
        for (int i = 0; i < uses; i++)
            res += odd[i];
        cout << res << "\n";
    }
    return 0;
}