#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r, a;
    cin >> l >> r >> a;
    if (l > r)
        swap(l, r);
    int tk = min(r - l, a);
    l += tk;
    a -= tk;
    cout << 2 * (l + a / 2) << "\n";
    return 0;
}
