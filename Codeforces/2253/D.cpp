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
        int s = x + y;
        int len = 0;
        while (len <= s)
            s -= len++;
        len--;
        string res(len, '?');
        char c1 = 'X', c2 = 'Y';
        for (int i = 0; i < len; i++) {
            if (x > y) {
                swap(x, y);
                swap(c1, c2);
            }
            y -= (len - i);
            res[i] = c2;
        }
        cout << res << "\n";
    }
    return 0;
}
