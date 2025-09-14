#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X, C;
    cin >> X >> C;
    int res = X / (1000 + C);
    cout << 1000 * res << "\n";
    return 0;
}