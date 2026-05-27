#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            M[a]++;
        }
        int res = 0;
        for (auto& [key, val] : M)
            res = max(res, val);
        cout << n - res + 1 << "\n";
    }
    return 0;
}
