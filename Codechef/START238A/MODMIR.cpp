#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n % 3 != 2) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; i++)
            cout << (i % 3 ? (i / 3 % 2 ? 1 : m - 1) : 0) << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
