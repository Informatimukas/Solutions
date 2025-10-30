#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M;
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        M[b]++;
        M[d]--;
    }
    int cur = 0;
    for (auto& [y, delt] : M) {
        cur += delt;
        if (cur > mx) {
            mx = cur;
            ans = y;
        }
    }
    cout << ans << " " << mx << "\n";
    return 0;
}