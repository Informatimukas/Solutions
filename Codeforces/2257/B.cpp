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
        int sum1 = n, sum2 = m;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i == 0)
                sum1 += a;
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (i == 0)
                sum2 += a;
        }
        if (sum1 >= sum2)
            cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}
