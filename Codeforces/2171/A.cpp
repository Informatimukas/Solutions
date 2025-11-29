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
        int res = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (2 * i + 4 * j == n)
                    res++;
        cout << res << "\n";
    }
    return 0;
}
