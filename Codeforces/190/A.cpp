#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m > 0 && n == 0) {
        cout << "Impossible\n";
        return 0;
    }
    if (m == 0) {
        cout << n << " " << n << "\n";
        return 0;
    }
    cout << max(n, m) << " " << n + m - 1 << "\n";
    return 0;
}
