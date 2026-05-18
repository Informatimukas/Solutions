#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x]++;
    }
    auto mx = ranges::max_element(M, {}, [](auto&& x) { return x.second; })->second;
    while (mx % k)
        mx++;
    int res = 0;
    for (auto x : M | views::values)
        res += mx - x;
    cout << res << "\n";
    return 0;
}
