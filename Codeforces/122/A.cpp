#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector nums = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    for (auto& x : nums)
        if (n % x == 0) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}