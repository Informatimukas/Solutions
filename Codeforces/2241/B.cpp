#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int num = x;
        int my = 1;
        while (num) {
            my *= 10;
            num /= 10;
        }
        my++;
        cout << my << "\n";
    }
    return 0;
}
