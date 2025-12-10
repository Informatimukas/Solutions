#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    int res = 100000;
    for (int i = n - 1; i < a.size(); i++)
        res = min(res, a[i] - a[i - (n - 1)]);
    cout << res << "\n";
    return 0;
}