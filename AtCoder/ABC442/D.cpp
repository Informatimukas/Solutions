#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    vector S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    while (m--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x;
            cin >> x;
            swap(A[x], A[x + 1]);
            S[x] = S[x - 1] + A[x];
        } else {
            int l, r;
            cin >> l >> r;
            cout << S[r] - S[l - 1] << "\n";
        }
    }
    return 0;
}
