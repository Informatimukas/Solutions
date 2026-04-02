#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int lef = 1, rig = 10005;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        int cnt = 0;
        for (auto x : a)
            cnt += x / mid;
        if (cnt >= m)
            lef = mid + 1;
        else rig = mid - 1;
    }
    cout << rig << "\n";
    return 0;
}
