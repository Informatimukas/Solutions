#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int res = (n - 1) * min(a, b);
    if (n > 1)
        res = min(res, min(a, b) + (n - 2) * min({a, b, c}));
    cout << res << "\n";
    return 0;
}
