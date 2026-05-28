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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector res(n + 1, 1);
        int best = 0;
        for (int i = n; i >= 1; i--) {
            for (int j = i + i; j <= n; j += i)
                if (a[i] < a[j])
                    res[i] = max(res[i], res[j] + 1);
            best = max(best, res[i]);
        }
        cout << best << "\n";
    }
    return 0;
}
