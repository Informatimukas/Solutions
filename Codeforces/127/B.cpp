#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ++M[a];
    }
    int res = 0;
    for (auto& c : M | views::values)
        res += c / 2;
    cout << res / 2 << "\n";
    return 0;
}
