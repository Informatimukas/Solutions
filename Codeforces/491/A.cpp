#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int n = a + b + 1;
    cout << n - a;
    for (int i = n - a + 1; i <= n; i++)
        cout << " " << i;
    for (int i = n - a - 1; i >= 1; i--)
        cout << " " << i;
    cout << "\n";
    return 0;
}
