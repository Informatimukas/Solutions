#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string a = "aa";
    string b = "bb";
    cin >> n;
    while (n >= 2) {
        n -= 2;
        cout << a;
        swap(a, b);
    }
    if (n == 1)
        cout << a[0];
    cout << "\n";
    return 0;
}