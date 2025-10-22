#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r = 0, c = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '*') {
                r ^= i;
                c ^= j;
            }
        }
    cout << r << " " << c << "\n";
    return 0;
}