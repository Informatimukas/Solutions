#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a <= b)
            cout << "-1\n";
        else cout << min(a - b, b) << "\n";
    }
    return 0;
}
