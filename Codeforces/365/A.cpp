#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int res = 0;
    while (n--) {
        int a;
        cin >> a;
        int mask = 0;
        while (a) {
            if (a % 10 <= k)
                mask |= 1 << (a % 10);
            a /= 10;
        }
        if (mask == (1 << (k + 1)) - 1)
            res++;
    }
    cout << res << "\n";
    return 0;
}
