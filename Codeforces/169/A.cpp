#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (auto& y : x)
        cin >> y;
    ranges::sort(x);
    cout << x[b] - x[b - 1] << "\n";
    return 0;
}