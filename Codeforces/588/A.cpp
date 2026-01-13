#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cost = 10000;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        cost = min(cost, p);
        res += a * cost;
    }
    cout << res << "\n";
    return 0;
}
