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
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
        }
        if (n == 1)
            cout << "1\n";
        else for (int i = 0; i < n; i++)
                cout << "2" << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
