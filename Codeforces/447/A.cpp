#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, n;
    cin >> p >> n;
    set<int> S;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (!S.insert(a % p).second) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
