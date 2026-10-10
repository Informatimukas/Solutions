#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    int i = 0, j = 0;
    int dif = 0;
    int res = 0;
    while (i < n || j < m) {
        if (dif >= 0)
            dif -= b[j++];
        else dif += a[i++];
        res += dif == 0;
    }
    cout << res << "\n";
    return 0;
}
