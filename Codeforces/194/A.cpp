#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int res = 3 * n <= k ? 0 : 3 * n - k;
    cout << res << "\n";
    return 0;
}