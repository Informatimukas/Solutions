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
        bool found = false;
        while (n--) {
            int a;
            cin >> a;
            if (a == 67)
                found = true;
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
