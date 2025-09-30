#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            M[a]++;
        }
        map<int, int> C;
        for (auto& cnt : M | views::values)
            for (int i = 1; i <= cnt; i++)
                C[i]++;
        int res = 0;
        for (auto& [key, val] : C)
            res = max(res, key * val);
        cout << res << "\n";
    }
    return 0;
}
