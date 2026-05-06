#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    int res = 0;
    while (2 * sum < n * (2 * k - 1)) {
        sum += k;
        res++;
        n++;
    }
    cout << res << "\n";
    return 0;
}
