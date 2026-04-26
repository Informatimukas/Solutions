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
        bool res = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 100)
                res = true;
        }
        cout << (res ? "Yes" : "No") << "\n";
    }
    return 0;
}
