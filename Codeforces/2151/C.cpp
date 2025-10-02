#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> A(2 * n);
        vector S(A.size(), 0ll);
        for (int i = 0; i < 2 * n; i++) {
            cin >> A[i];
            if (i >= 1) {
                S[i] = A[i] - A[i - 1];
                if (i >= 2)
                    S[i] += S[i - 2];
            }
        }
        ll res = 0;
        cout << S[2 * n - 1];
        for (int i = 1; i < n; i++) {
            res += A[2 * n - i] - A[i - 1];
            ll cur = res + S[2 * n - i - 1] - S[i - 1];
            cout << " " << cur;
        }
        cout << "\n";
    }
    return 0;
}