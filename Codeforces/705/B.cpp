#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res = (res + a - 1) % 2;
        cout << (res % 2 ? 1 : 2) << "\n";
    }
    return 0;
}
