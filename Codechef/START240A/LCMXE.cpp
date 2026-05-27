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
        ll z;
        cin >> z;
        vector<int> mx(z + 1);
        for (int i = 2; i <= z; i++)
            if (mx[i] == 0)
                for (int j = i; j <= z; j += i)
                    mx[j] = i;
        ll res = z * z;
        for (int i = 1; i <= z; i++) {
            int num = i;
            ll my = 1;
            while (num > 1) {
                int cur = mx[num];
                int cnt = 0;
                while (mx[num] == cur) {
                    cnt++;
                    num /= cur;
                }
                my *= (2 * cnt + 1);
            }
            res -= my;
        }
        cout << res << "\n";
    }
    return 0;
}
