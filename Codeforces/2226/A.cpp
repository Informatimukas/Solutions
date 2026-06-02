#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0, lst;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a > 1)
                res += a;
            lst = a;
        }
        if (lst == 1)
            res++;
        cout << res << "\n";
    }
    return 0;
}
