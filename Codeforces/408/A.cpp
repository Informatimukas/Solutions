#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> k(n);
    for (auto& x : k)
        cin >> x;
    int res = 1000000000;
    for (int i = 0; i < n; i++) {
        int cand = k[i] * 15;
        for (int j = 0; j < k[i]; j++) {
            int a;
            cin >> a;
            cand += a * 5;
        }
        res = min(res, cand);
    }
    cout << res << "\n";
    return 0;
}
