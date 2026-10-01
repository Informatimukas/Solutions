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
        int a0, a1, a2;
        cin >> a0 >> a1 >> a2;
        int mn = min({a0, a1, a2});
        cout << n - mn << "\n";
    }
    return 0;
}
