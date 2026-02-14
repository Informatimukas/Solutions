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
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;
    auto sum = accumulate(a.begin(), a.end(), 0ll);
    ranges::sort(b, greater());
    if (sum <= b[0] + b[1])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}