#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    char a = 'B', b = 'G';
    if (n < m) {
        swap(n, m);
        swap(a, b);
    }
    while (n > 0 || m > 0) {
        if (n > 0) {
            cout << a;
            n--;
        }
        swap(n, m);
        swap(a, b);
    }
    cout << "\n";
    return 0;
}
