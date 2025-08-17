#include <bits/stdc++.h>
using namespace std;

bool Prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    ++n;
    while (!Prime(n))
        ++n;
    cout << (n == m? "YES": "NO") << "\n";
    return 0;
}