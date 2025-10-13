#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    int res = 0;
    for (int i = 1; i <= x; i++)
        res = (res + i) % 10;
    cout << res << "\n";
    return 0;
}