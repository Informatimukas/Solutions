#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<ll, 2> Get() {
    int n;
    cin >> n;
    array<ll, 2> res{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res[a % 2]++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        auto A = Get();
        auto B = Get();
        cout << A[0] * B[0] + A[1] * B[1] << "\n";
    }
    return 0;
}
