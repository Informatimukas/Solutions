#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 100)
            res1++;
        else res2++;
    }
    if (res1 % 2 == 0 && (res1 > 0 || res2 % 2 == 0))
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
