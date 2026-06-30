#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, s;
    cin >> a >> b >> s;
    s -= (abs(a) + abs(b));
    cout << (s >= 0 && s % 2 == 0 ? "Yes" : "No") << "\n";
    return 0;
}
