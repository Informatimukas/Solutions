#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = n / 2; i >= 0; i--)
        cout << string(i, '*') << string(n - 2 * i, 'D') << string(i, '*') << "\n";
    for (int i = 1; i <= n / 2; i++)
        cout << string(i, '*') << string(n - 2 * i, 'D') << string(i, '*') << "\n";
    return 0;
}
