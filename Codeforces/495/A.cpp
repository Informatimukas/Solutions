#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const array cnt{2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    int x;
    cin >> x;
    cout << cnt[x / 10] * cnt[x % 10] << "\n";
    return 0;
}
