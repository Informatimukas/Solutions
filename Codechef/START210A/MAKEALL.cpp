#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cur = 1;
    for (int i = 0; i < 10; i++) {
        if (cur != 1)
            cout << " ";
        cout << cur << " " << 2 * cur;
        cur *= 3;
    }
    cout << "\n";
    return 0;
}
