#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int k, x;
        cin >> k >> x;
        cout << x * (1 << k) << "\n";
    }
    return 0;
}