#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        set<int> S;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(a);
        }
        for (int i = 1; ; i++)
            if (!S.contains(i) && x-- == 0) {
                cout << i - 1 << "\n";
                break;
            }
    }
    return 0;
}
