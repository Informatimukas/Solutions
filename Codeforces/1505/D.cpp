#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<int> S;
    while (n) {
        if (S.contains(n % m)) {
            cout << "NO\n";
            return 0;
        }
        S.insert(n % m);
        n /= m;
    }
    cout << "YES\n";
    return 0;
}
