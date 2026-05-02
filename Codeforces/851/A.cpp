#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, t;
    cin >> n >> k >> t;
    cout << min({k, n + k - t, t}) << "\n";
    return 0;
}
