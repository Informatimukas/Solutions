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
        int lst = -1, res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (lst != -1 && (lst == a || lst + a == 7)) {
                ++res;
                lst = -1;
            } else lst = a;
        }
        cout << res << "\n";
    }
    return 0;
}
