#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a, greater());
    int i = 0;
    while (i < n && k < m)
        k += a[i++] - 1;
    if (k < m)
        i = -1;
    cout << i << "\n";
    return 0;
}
