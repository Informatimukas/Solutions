#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& z : a)
        cin >> z;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 1; j <= x; j++)
            if (i - j >= 0 && a[i] >= a[i - j]) {
                ok = false;
                break;
            }
        for (int j = 1; j <= y; j++)
            if (i + j < n && a[i] >= a[i + j]) {
                ok = false;
                break;
            }
        if (ok) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}
