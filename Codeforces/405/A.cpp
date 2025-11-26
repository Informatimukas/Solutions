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
    for (int i = 0; i < n; i++)
        cout << a[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}