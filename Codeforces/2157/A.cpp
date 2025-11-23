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
        vector count(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            count[a]++;
        }
        int res = 0;
        for (int i = 0; i <= n; i++)
            if (count[i] >= i)
                res += count[i] - i;
            else res += count[i];
        cout << res << "\n";
    }
    return 0;
}
