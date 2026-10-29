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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> my(n);
        map<int, int> M;
        ll res = 0;
        for (int i = 0; i + 4 < n; i++) {
            my[i] = a[i] + a[i + 2] - a[i + 4];
            res += M[my[i]]++;
            if (i - 2 >= 0 && my[i - 2] == my[i])
                res--;
            if (i - 4 >= 0 && my[i - 4] == my[i])
                res--;
        }
        cout << res << "\n";
    }
    return 0;
}
