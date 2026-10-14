#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= m; i++) {
        int s1 = accumulate(a.begin(), a.begin() + i, 0);
        int s2 = accumulate(a.begin() + i, a.end(), 0);
        if (x <= s1 && s1 <= y && x <= s2 && s2 <= y) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
