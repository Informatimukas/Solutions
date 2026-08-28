#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (cur < a) {
            cout << "NO\n";
            return 0;
        }
        cur = max(cur, b);
    }
    if (cur < m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
