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
    auto mx = *ranges::max_element(a);
    int pnt = 0;
    while (a[pnt] != mx && a[pnt] < a[pnt + 1])
        pnt++;
    if (a[pnt] != mx) {
        cout << "NO\n";
        return 0;
    }
    int pnt2 = n - 1;
    while (a[pnt2] != mx && a[pnt2] < a[pnt2 - 1])
        pnt2--;
    if (a[pnt2] != mx) {
        cout << "NO\n";
        return 0;
    }
    for (int i = pnt; i <= pnt2; i++)
        if (a[i] != mx) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
