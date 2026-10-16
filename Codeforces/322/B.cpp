#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, g, b;
    cin >> r >> g >> b;
    int res = 0;
    for (int i = 0; i <= 2; i++)
        if (i <= r && i <= g && i <= b)
            res = max(res, i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3);
    cout << res << "\n";
    return 0;
}
