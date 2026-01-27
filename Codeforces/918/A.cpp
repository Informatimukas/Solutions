#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string res(n, 'o');
    int a = 1, b = 1;
    res[0] = 'O';
    while (a + b <= n) {
        int c = a + b;
        a = b;
        b = c;
        res[c - 1] = 'O';
    }
    cout << res << "\n";
    return 0;
}