#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    sort(A.begin() + 1, A.end());
    vector<ll> B(n + 1);
    for (int i = 1; i <= n; i++)
        B[i] = B[i - 1] + A[i];
    while (q--) {
        int b;
        cin >> b;
        auto ind = distance(A.begin(), lower_bound(A.begin() + 1, A.end(), b));
        if (ind >= A.size())
            cout << "-1\n";
        else {
            ll sum = B[ind - 1] + (n - ind + 1) * (b - 1) + 1;
            cout << sum << "\n";
        }
    }
    return 0;
}
