#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a;
        cin >> n >> a;
        int smaller = 0, bigger = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < a)
                smaller++;
            else if (x > a)
                bigger++;
        }
        if (smaller >= bigger)
            cout << a - 1 << "\n";
        else cout << a + 1 << "\n";
    }
    return 0;
}
