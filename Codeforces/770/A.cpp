#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cout << static_cast<char>('a' + i % k);
    cout << "\n";
    return 0;
}
