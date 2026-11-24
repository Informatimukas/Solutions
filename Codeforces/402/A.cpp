#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, a, b, v;
    cin >> k >> a >> b >> v;
    int X;
    for (X = 1; ; X++) {
        int s = min(b + X, X * k);
        if (s * v >= a) break;
    }
    cout << X << "\n";
    return 0;
}
