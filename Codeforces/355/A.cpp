#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, d;
    cin >> k >> d;
    if (k == 1) {
        cout << d << "\n";
        return 0;
    }
    if (d == 0) {
        cout << "No solution\n";
        return 0;
    }
    int nd = (d - 1) % 9;
    if (nd == 0)
        nd = 9;
    cout << "1" << string(k - 2, '0') << nd << "\n";
    return 0;
}
