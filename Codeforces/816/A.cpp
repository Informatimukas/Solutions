#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int h = 10 * (s[0] - '0') + (s[1] - '0');
    int m = 10 * (s[3] - '0') + (s[4] - '0');
    int res = 0;
    while (h / 10 != m % 10 || h % 10 != m / 10) {
        res++;
        if (++m >= 60) {
            m = 0;
            if (++h >= 24)
                h = 0;
        }
    }
    cout << res << "\n";
    return 0;
}
