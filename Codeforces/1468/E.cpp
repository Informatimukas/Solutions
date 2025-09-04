#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        array<int, 4> a;
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        cout << a[0] * a[2] << "\n";
    }
    return 0;
}