#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int d = 2;
        while (n % d)
            ++d;
        n += d + (k - 1) * 2;
        cout << n << "\n";
    }
    return 0;
}
