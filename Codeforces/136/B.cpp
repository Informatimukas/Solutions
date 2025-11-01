#include <bits/stdc++.h>
using namespace std;

int Solve(int a, int c) {
    if (a == 0 && c == 0)
        return 0;
    int cur = (c % 3 - a % 3 + 3) % 3;
    return Solve(a / 3, c / 3) * 3 + cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, c;
    cin >> a >> c;
    cout << Solve(a, c) << "\n";
    return 0;
}