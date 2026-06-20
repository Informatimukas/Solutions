#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ii> seq(n);
    for (auto& [l, r] : seq)
        cin >> l >> r;
    ranges::sort(seq, {}, [](auto&& x) { return x.second; });
    int lef = 1, rig = 1000000007;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        int lst = -mid;
        int cnt = 0;
        for (auto& [l, r] : seq)
            if (lst + mid <= l) {
                cnt++;
                lst = r;
            }
        if (cnt >= k)
            lef = mid + 1;
        else rig = mid - 1;
    }
    if (rig < 1)
        rig = -1;
    cout << rig << "\n";
    return 0;
}
