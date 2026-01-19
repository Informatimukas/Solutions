#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if ((n - 2) % 3)
        cout << "1 1 " << n - 2 << "\n";
    else cout << "1 2 " << n - 3 << "\n";
    return 0;
}
