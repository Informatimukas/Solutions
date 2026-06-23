#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, n;
    cin >> n >> a;
    vector<int> seq(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        res += seq[i];
    }
    for (int i = 1; i <= n; i++)
        if (seq[i]) {
            int j = 2 * a - i;
            if (1 <= j && j <= n && seq[j] == 0)
                res--;
        }
    cout << res << "\n";
    return 0;
}
