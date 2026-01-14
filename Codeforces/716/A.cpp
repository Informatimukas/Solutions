#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int pnt = n - 2;
    while (pnt >= 0 && a[pnt + 1] - a[pnt] <= c)
        --pnt;
    cout << n - 1 - pnt << "\n";
    return 0;
}
