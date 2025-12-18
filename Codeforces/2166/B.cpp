#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        int res = 1;
        if (static_cast<long long>(n) * b > a && b != a)
            ++res;
        cout << res << "\n";
    }
    return 0;
}
