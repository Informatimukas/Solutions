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
        for (int i = n; i > 0; i--)
            cout << i << (i - 1 > 0 ? ' ' : '\n');
    }
    return 0;
}
