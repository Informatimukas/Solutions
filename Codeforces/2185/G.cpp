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
        vector<int> lens(n), a(n), b(n);
        vector<map<int, int>> M(n);
        map<int, int> GM;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> lens[i];
            sum += lens[i];
            for (int j = 0; j < lens[i]; j++) {
                int x;
                cin >> x;
                M[i][x]++;
                GM[x]++;
            }
            a[i] = 0;
            while (M[i].contains(a[i]))
                a[i]++;
            b[i] = a[i] + 1;
            while (M[i].contains(b[i]))
                b[i]++;
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += (sum - lens[i]) * (n - 2) * a[i];
            for (auto& [key, value] : M[i]) {
                ll nw = key < a[i] && value == 1 ? key : a[i];
                res += nw * value * (n - 1);
            }
            ll good = GM[a[i]];
            res += good * b[i];
            res += (sum - lens[i] - good) * a[i];
        }
        cout << res << "\n";
    }
    return 0;
}
