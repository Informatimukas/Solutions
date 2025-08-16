#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> R(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i] >> C[i];
    }
    ranges::sort(R);
    ranges::sort(C);
    int res = max(R.back() - R[0], C.back() - C[0]);
    cout << (res + 1) / 2 << "\n";
    return 0;
}