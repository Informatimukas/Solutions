#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 3> a{};
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    if (a[2] - a[0] >= 10)
        cout << "check again\n";
    else cout << "final " << a[1] << "\n";
    return 0;
}
