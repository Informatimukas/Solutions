#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        set<int> S;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(a);
        }
        int cur = 0;
        while (cur < k - 1 && S.contains(cur))
            ++cur;
        cout << cur << "\n";
    }
    return 0;
}
