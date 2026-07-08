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
    if (a.back() == 0)
        cout << "UP\n";
    else if (a.back() == 15)
        cout << "DOWN\n";
    else if (a.size() == 1)
        cout << "-1\n";
    else if (a[a.size() - 2] > a.back())
        cout << "DOWN\n";
    else cout << "UP\n";
    return 0;
}
