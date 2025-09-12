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
        vector<int> a(n * k);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        long long res = 0;
        int sub = n / 2 + 1;
        for (int i = 1; i <= k; i++)
            res += a[a.size() - i * sub];
        cout << res << "\n";
    }
    return 0;
}