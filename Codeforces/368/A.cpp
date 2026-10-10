#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    int m;
    cin >> m;
    int res = 0;
    for (int i = 0; i < m; i++)
        if (i < a.size())
            res += a[i];
        else res -= d;
    cout << res << "\n";
    return 0;
}
