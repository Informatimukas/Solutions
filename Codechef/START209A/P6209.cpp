#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for (auto& x : A)
            cin >> x;
        vector<int> B(m);
        for (auto& x : B)
            cin >> x;
        ranges::sort(A, greater());
        ranges::sort(B, greater());
        int tk = min(n, m);
        map<int, int> M;
        ll res = 0;
        for (int i = 0; i < tk; i++) {
            res += A[i] + B[i];
            M[A[i]]++;
            M[B[i]]++;
        }
        int badKey = 0, badCount = 0;
        for (auto& [key, value] : M)
            if (value > tk) {
                badKey = key;
                badCount = value - tk;
                res -= 2 * static_cast<ll>(key) * badCount;
                break;
            }
        for (int i = tk; i < A.size(); i++)
            if (badCount > 0 && A[i] != badKey) {
                res += A[i] + badKey;
                badCount--;
            }
        for (int i = tk; i < B.size(); i++)
            if (badCount > 0 && B[i] != badKey) {
                res += B[i] + badKey;
                badCount--;
            }
        cout << res << "\n";
    }
    return 0;
}
