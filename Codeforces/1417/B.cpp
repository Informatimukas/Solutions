#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, val;
        cin >> n >> val;
        int col1 = 0, col2 = 1;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int b = val - a;
            int res;
            if (a < b)
                res = 0;
            else if (a > b)
                res = 1;
            else {
                res = col1;
                swap(col1, col2);
            }
            cout << res << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
