#include <bits/stdc++.h>
using namespace std;

array<int, 3> getMoves(ranges::range auto&& r, int lst) {
    auto it = ranges::begin(r);
    auto end = ranges::end(r);
    int cur = 0;
    while (cur <= lst && it != end) {
        cur += *it;
        ++it;
    }
    if (it == end)
        return {1, cur, 0};
    auto got = getMoves(ranges::subrange(it, end) | views::reverse, cur);
    return {got[0] + 1, cur + got[2], got[1]};
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        auto res = getMoves(a, 0);
        cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    }
    return 0;
}
