#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, b, d;
    cin >> n >> b >> d;
    int res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= b) {
            cur += a;
            if (cur > d) {
                res++;
                cur = 0;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
