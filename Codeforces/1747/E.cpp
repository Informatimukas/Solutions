#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll sum = 0;
    for (int i = 0; i <= 50; i++) {
        ll my = (i + 2) * (i + 1) * (i + 3);
        if (i % 2) my = -my;
        sum += my;
        cout << sum << "\n";
    }
    return 0;
}