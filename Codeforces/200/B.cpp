#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sum += p;
    }
    cout << fixed << setprecision(10) << 100.0l * sum / (100 * n) << "\n";
    return 0;
}