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
        for (int i = 1; i <= n; i++) {
            int r = i % 2 ? i + 1 : i - 1;
            cout << r << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
