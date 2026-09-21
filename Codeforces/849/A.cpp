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
    if (n % 2 && a[0] % 2 && a.back() % 2)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
