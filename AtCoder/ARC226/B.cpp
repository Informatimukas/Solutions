#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 2000000000000000000ll;
constexpr int Maxb = 61;

bool Check(ll mask, int n, const array<int, Maxb>& cnt) {
    ll has = 0;
    for (int i = Maxb - 1; i >= 0; i--) {
        if (mask & 1ll << i)
            has += n;
        if (cnt[i] > has)
            return false;
        has -= cnt[i];
        has = min(Inf, 2 * has);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        array<int, Maxb> cnt{};
        for (int i = 0; i < m; i++)
            cin >> cnt[i];
        ll lef = 0, rig = Inf;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            if (Check(mid, n, cnt))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
