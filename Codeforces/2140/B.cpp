#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int nines = 9;
        while (nines <= x)
            nines = 10 * nines + 9;
        if ((nines - x) <= nines / 9)
            nines = 10 * nines + 9;
        cout << nines - x << "\n";
    }
    return 0;
}