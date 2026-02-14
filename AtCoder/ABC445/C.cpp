#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        if (a[i] > i)
            a[i] = a[a[i]];
    for (int i = 1; i <= n; i++)
        cout << a[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
