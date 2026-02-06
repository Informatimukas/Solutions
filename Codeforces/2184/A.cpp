#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n <= 3)
            cout << n << "\n";
        else cout << n % 2 << "\n";
    }
    return 0;
}
