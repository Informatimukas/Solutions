#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int getBit(int x) {
    int res = 0;
    while (!(x & 1 << res))
        res++;
    return res;
}

void Print(ll x) {
    cout << "! " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int val = getBit(Ask(1, n));
    int res = 20, lef = 1, rig = n;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        int got = getBit(Ask(1, mid));
        if (got == val)
            rig = mid - 1;
        else {
            res = got;
            lef = mid + 1;
        }
    }
    if (lef < n)
        res = min(res, getBit(Ask(lef + 1, n)));
    Print(1ll << static_cast<ll>(res + val));
    return 0;
}