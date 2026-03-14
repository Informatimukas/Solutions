#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> s(n);
    for (auto& x : s)
        cin >> x;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    int mn = *ranges::min_element(s);
    int mx = *ranges::max_element(b);
    if (mn <= mx) {
        int buy = r / mn;
        r %= mn;
        r += buy * mx;
    }
    cout << r << "\n";
    return 0;
}