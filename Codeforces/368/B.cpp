#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    set<int> S;
    for (int i = n; i >= 1; i--)
        a[i] = a[i + 1] + S.insert(a[i]).second;
    while (m--) {
        int l;
        cin >> l;
        cout << a[l] << "\n";
    }
    return 0;
}
