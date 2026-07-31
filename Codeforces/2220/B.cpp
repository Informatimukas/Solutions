#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[i] == a[j])
                j++;
            res = max(res, j - i);
        }
        cout << (res < m ? "YES" : "NO") << "\n";
    }
    return 0;
}
