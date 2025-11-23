#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int res = -1;
        for (int j = 1; j < i; j++)
            if (a[j] > a[i])
                res = j;
        cout << res << "\n";
    }
    return 0;
}