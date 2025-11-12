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
        int lst = 0, res = 0;
        map<int, int> M;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (M.contains(a)) {
                int prv = M[a];
                if (lst < prv) {
                    res++;
                    lst = i - 1;
                }
            }
            M[a] = i;
        }
        cout << res << "\n";
    }
    return 0;
}
