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
        for (int i = 1; i < 2 * n; i += 2)
            cout << i << (i + 2 < 2 * n ? ' ' : '\n');
    }
    return 0;
}
