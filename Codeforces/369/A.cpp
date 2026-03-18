#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a == 1)
            if (m == 0) ++res;
            else --m;
        else if (k > 0)
                --k;
            else if (m > 0)
                --m;
            else ++res;
    }
    cout << res << "\n";
    return 0;
}
