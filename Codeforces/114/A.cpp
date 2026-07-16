#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, l;
    cin >> k >> l;
    int res = 0;
    while (l % k == 0) {
        res++;
        l /= k;
    }
    if (l == 1)
        cout << "YES\n" << res - 1 << "\n";
    else cout << "NO\n";
    return 0;
}
