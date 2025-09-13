#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        int lef = 0, rig = 1000000000;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            ll sum = 0;
            for (int i = 0; i < n; i++)
                if (a[i] > mid)
                    sum += b[i];
            if (sum <= mid) rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}