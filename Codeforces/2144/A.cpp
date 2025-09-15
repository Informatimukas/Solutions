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
        int md = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            md = (md + a) % 3;
        }
        if (md == 0)
            cout << "1 2\n";
        else cout << "0 0\n";
    }
    return 0;
}
