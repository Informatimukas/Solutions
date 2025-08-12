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
        vector<int> p(n);
        for (auto& x : p)
            cin >> x;
        p.push_back(0);
        ll res = 0, s = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (p[i] < p[i + 1]) s++;
            else s += n - i;
            res += s;
        }
        cout << res << "\n";
    }
    return 0;
}