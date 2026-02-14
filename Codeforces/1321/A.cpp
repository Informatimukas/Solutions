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
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;
    int his = 0, my = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1 && b[i] == 0)
            my++;
        else if (a[i] == 0 && b[i] == 1)
            his++;
    if (my == 0)
        cout << "-1\n";
    else cout << his / my + 1 << "\n";
    return 0;
}
