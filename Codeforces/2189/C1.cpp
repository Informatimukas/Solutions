#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        set<int> S;
        for (int i = 2; i <= n; i++)
            S.insert(i);
        a[n] = 1;
        for (int i = n - 1; i > 1; i--) {
            a[i] = 1 ^ i;
            S.erase(a[i]);
        }
        a[1] = *S.begin();
        for (int i = 1; i <= n; i++)
            cout << a[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
