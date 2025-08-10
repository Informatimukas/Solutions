#include <bits/stdc++.h>
using namespace std;

constexpr int Maxc = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector mn(m, Maxc);
    while (n--) {
        int r, c;
        cin >> r >> c;
        r--;
        mn[r] = min(mn[r], c);
    }
    cout << min(k, accumulate(mn.begin(), mn.end(), 0)) << "\n";
    return 0;
}