#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 10000000000000000ll;

bool Check(map<int, ll> M, int x) {
    ll nd = 1;
    for (int i = x - 1; i > 0 && nd < Inf; i--) {
        ll got = M[i];
        if (got > nd)
            M[0] += got - nd;
        else nd += nd - got;
    }
    return M[0] >= nd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, ll> M;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            M.emplace(a, b);
            mx = max(mx, a);
        }
        int lef = mx + 1, rig = mx + 60;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(M, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
