#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 2000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, x;
        cin >> a >> b >> x;
        int res = Inf;
        int cur = 0;
        while (a != b) {
            if (a > b)
                swap(a, b);
            res = min(res, cur + b - a);
            b /= x;
            cur++;
        }
        res = min(res, cur);
        cout << res << "\n";
    }
    return 0;
}
