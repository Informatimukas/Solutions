#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n > m)
            swap(n, m);
        if (n == 1 || m <= 2)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
