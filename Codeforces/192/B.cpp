#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = min(a[0], a[n - 1]);
    for (int i = 0; i + 1 < n; i++)
        res = min(res, max(a[i], a[i + 1]));
    cout << res << "\n";
    return 0;
}
