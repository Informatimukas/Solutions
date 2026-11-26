#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    int res = a % 2 ? a / 2 + 1 : (n - a) / 2 + 1;
    cout << res << "\n";
    return 0;
}
