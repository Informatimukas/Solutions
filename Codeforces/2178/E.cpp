#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll sum = Ask(1, n);
        int L = 1, R = n;
        while (L < R) {
            int lef = L, rig = R - 1;
            int split = L;
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                ll cur = Ask(L, mid);
                ll oth = sum - cur;
                if (cur == oth) {
                    split = mid;
                    break;
                }
                if (cur < oth)
                    lef = mid + 1;
                else rig = mid - 1;
            }
            if (split - L + 1 <= R - split)
                R = split;
            else L = split + 1;
            sum /= 2;
        }
        cout << "! " << sum << endl;
    }
    return 0;
}
