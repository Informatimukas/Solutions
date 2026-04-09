#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int lef = 0, rig = n - 1;
    while (lef < n && a[lef] == 0)
        lef++;
    if (lef >= n) {
        cout << "0\n";
        return 0;
    }
    while (a[rig] == 0)
        rig--;
    int res = rig - lef + 1;
    for (int i = lef, j; i <= rig; i = j) {
        j = i;
        while (j <= rig && a[i] == a[j])
            ++j;
        if (a[i] == 0 && j - i > 1)
            res -= (j - i);
    }
    cout << res << "\n";
    return 0;
}
