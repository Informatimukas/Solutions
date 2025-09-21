#include <bits/stdc++.h>
using namespace std;

bool Check(int a, int b) {
    if (a > b)
        swap(a, b);
    return b <= 2 * (a + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (Check(a, b) && Check(c - a, d - b) ? "YES" : "NO") << "\n";
    }
    return 0;
}