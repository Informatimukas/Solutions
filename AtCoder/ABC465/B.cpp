#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    int cnt = max(0, min(b, r) - max(a, l));
    cout << x * cnt + y * (b - a - cnt) << "\n";
    return 0;
}
