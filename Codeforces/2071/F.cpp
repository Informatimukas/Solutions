#include <bits/stdc++.h>
using namespace std;

int countBad(int x, const vector<int>& a) {
    vector delt(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
        if (a[i] < x) {
            int r = x - a[i];
            int lef = max(0, i - r + 1);
            int rig = min(static_cast<int>(a.size()), i + r);
            delt[lef]++;
            if (rig < delt.size())
                delt[rig]--;
        }
    int res = a.size();
    int cur = 0;
    for (int i = 0; i < delt.size(); i++) {
        cur += delt[i];
        if (a[i] >= x)
            res = min(res, cur);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int lef = 1, rig = 1000000000;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (countBad(mid, a) > k)
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
