#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int res = 0;
        set<int> good;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == k)
                res++;
            else if (a < k)
                good.insert(a);
        }
        res = max(res, k - static_cast<int>(good.size()));
        cout << res << "\n";
    }
    return 0;
}