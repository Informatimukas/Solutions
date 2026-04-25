#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        int res = 1;
        int s = abs(x - y);
        for (int i = 2; i <= s; i++)
            if (s % i == 0)
                res++;
        cout << res << "\n";
        for (int i = 0; i < x + y; i++)
            cout << (i < x ? 1 : -1) << (i + 1 < x + y ? ' ' : '\n');
    }
    return 0;
}
