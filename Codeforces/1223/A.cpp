#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 2)
            cout << "2\n";
        else cout << n % 2 << "\n";
    }
    return 0;
}
