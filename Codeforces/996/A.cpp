#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector seq = {1, 5, 10, 20, 100};
    int res = 0;
    for (auto& x : seq | views::reverse) {
        res += n / x;
        n %= x;
    }
    cout << res << "\n";
    return 0;
}