#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Gen(int lef, int rig, int cur, int mod, bool inc, int lst, array<vector<int>, 2>& M,
    const vector<int>& a) {
    if (lef > rig) {
        M[lst].push_back(cur);
        return;
    }
    int nlef = inc ? lef + 1 : lef;
    int nrig = inc ? rig : rig - 1;
    int ind = inc ? lef : rig;
    Gen(nlef, nrig, cur, mod, inc, 0, M, a);
    if (!lst)
        Gen(nlef, nrig, (cur + a[ind]) % mod, mod, inc, 1, M, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int mid = (n - 1) / 2;
    array<vector<int>, 2> M{};
    array<vector<int>, 2> R{};
    Gen(0, mid, 0, m, true, false, M, a);
    Gen(mid + 1, n - 1, 0, m, false, false, R, a);
    for (int i = 0; i < 2; i++) {
        ranges::sort(M[i]);
        ranges::sort(R[i]);
    }
    ll res = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) if (!(i && j)) {
            for (int l = 0, r; l < M[i].size(); l = r) {
                r = l;
                while (r < M[i].size() && M[i][l] == M[i][r])
                    r++;
                if (M[i][l] == 0) {
                    auto it = ranges::equal_range(R[j], 0);
                    res += static_cast<ll>(r - l) * distance(begin(it), end(it));
                }
                auto it = ranges::equal_range(R[j], m - M[i][l]);
                res += static_cast<ll>(r - l) * distance(begin(it), end(it));
            }
        }
    cout << res << "\n";
    return 0;
}
