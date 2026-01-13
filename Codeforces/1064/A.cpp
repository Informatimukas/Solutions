#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 3> a;
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    cout << max(0, a[2] + 1 - a[1] - a[0]) << "\n";
    return 0;
}
