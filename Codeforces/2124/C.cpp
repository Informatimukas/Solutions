#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (auto& el : b)
            cin >> el;
        int x = 1;
        for (int i = 0; i + 1 < n; i++)
            if (b[i + 1] % b[i]) {
                int g = __gcd(b[i], b[i + 1]);
                int oth = b[i] / g;
                x = x / __gcd(x, oth) * oth;
            }
        cout << x << "\n";
    }
    return 0;
}