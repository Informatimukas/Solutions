#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        int dsum = 0;
        while (num) {
            dsum += num % 10;
            num /= 10;
        }
        res += dsum == k;
    }
    cout << res << "\n";
    return 0;
}
