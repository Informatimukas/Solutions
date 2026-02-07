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
        set<int> S;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(a);
        }
        int lst = -2000000000;
        int cnt = 0, mx = 0;
        for (auto el : S) {
            if (lst + 1 == el)
                ++cnt;
            else cnt = 1;
            lst = el;
            mx = max(mx, cnt);
        }
        cout << mx << "\n";
    }
    return 0;
}
