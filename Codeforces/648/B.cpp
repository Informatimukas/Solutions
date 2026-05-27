#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " " << a[2 * n - 1 - i] << "\n";
    return 0;
}
