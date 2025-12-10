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
    array<int, 2> res{};
    int pl = 0, l = 0, r = n - 1;
    while (l <= r) {
        res[pl] += max(a[l], a[r]);
        pl = 1 - pl;
        if (a[l] > a[r])
            ++l;
        else --r;
    }
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}
