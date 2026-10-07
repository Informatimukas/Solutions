#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 1000000000;
    for (int x = 1; x <= n; x++) {
        int cand = 0;
        for (int i = 1; i <= n; i++)
            cand += 2 * (abs(x - i) + abs(i - 1) + abs(1 - x)) * a[i];
        res = min(res, cand);
    }
    cout << res << "\n";
    return 0;
}
