#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Solve(int b, auto&& range) {
    if (b < 0)
        return;
    int pnt = 0;
    while (pnt < range.size() && !(range[pnt] & 1 << b))
        pnt++;
    int p1 = pnt, p2 = range.size() - pnt;
    for (int i = 0; i < min(p1, p2); i++)
        swap(range[pnt + i], range[pnt - 1 - i]);
    if (p1 > p2)
        Solve(b - 1, ranges::subrange(range.begin(), range.begin() + p1 - p2));
    else if (p1 < p2)
        Solve(b - 1, ranges::subrange(range.begin() + 2 * p1, range.end()));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r - l + 1);
        iota(a.begin(), a.end(), l);
        Solve(29, ranges::subrange(a.begin(), a.end()));
        ll res = 0;
        for (int i = 0; i < a.size(); i++)
            res += (a[i] | (i + l));
        cout << res << "\n";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
