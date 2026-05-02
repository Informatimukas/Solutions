#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    if (accumulate(a.begin(), a.end(), 0) - ranges::max(a) <= s)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
