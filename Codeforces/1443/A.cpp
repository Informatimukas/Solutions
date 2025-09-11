#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << (4 * n - 2 * i) << (i + 1 < n? ' ': '\n');
    }
    return 0;
}