#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int na, nb;
    cin >> na >> nb;
    int n, m;
    cin >> n >> m;
    vector<int> a(na);
    for (auto& x : a)
        cin >> x;
    vector<int> b(nb);
    for (auto& x : b)
        cin >> x;
    cout << (a[n - 1] < b[nb - m] ? "YES" : "NO") << "\n";
    return 0;
}
