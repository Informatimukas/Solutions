#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::nth_element(a.begin(), a.begin() + n / 2, a.end());
    cout << a[n / 2] << "\n";
    return 0;
}
