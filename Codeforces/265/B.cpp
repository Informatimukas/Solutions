#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (i) res++;
        if (h < cur) {
            res += cur - h;
            cur = h;
        }
        res += h - cur;
        cur = h;
        res++;
    }
    cout << res << "\n";
    return 0;
}
