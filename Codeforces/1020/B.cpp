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
    for (int i = 1; i <= n; i++) {
        int x = i;
        set<int> S;
        while (!S.contains(x)) {
            S.insert(x);
            x = a[x];
        }
        cout << x << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
