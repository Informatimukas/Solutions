#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), ina(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ina[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        if (ina[i] != b) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
