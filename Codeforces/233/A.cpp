#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i += 2)
        cout << i + 1 << " " << i << (i + 2 <= n ? ' ' : '\n');
    return 0;
}
