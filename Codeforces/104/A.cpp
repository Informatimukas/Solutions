#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n -= 10;
    if (1 <= n && n < 10 || n == 11)
        cout << "4\n";
    else if (n == 10)
        cout << "15\n";
    else cout << "0\n";
    return 0;
}
