#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    int g = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        g = gcd(g, a[i + 1] - a[i]);
    cout << (a.back() - a[0]) / g - (n - 1) << "\n";
    return 0;
}
