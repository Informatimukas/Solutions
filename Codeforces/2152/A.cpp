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
        set<int> S;
        while (n--) {
            int a;
            cin >> a;
            S.insert(a);
        }
        cout << 2 * S.size() - 1 << "\n";
    }
    return 0;
}
