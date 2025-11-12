#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    int res = 0;
    while ((x + res) * 100 / n < y)
        res++;
    cout << res << "\n";
    return 0;
}