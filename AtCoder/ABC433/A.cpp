#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i <= 1000000; i++)
        if ((x + i) == (y + i) * z) {
            cout << "Yes\n";
            return 0;
        }
    cout << "No\n";
    return 0;
}