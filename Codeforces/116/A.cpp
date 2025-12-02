#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cur = 0, mx = 0;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cur += b - a;
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    return 0;
}