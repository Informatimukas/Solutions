#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, s, k;
        cin >> n >> s >> k;
        set<int> forb;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            forb.insert(x);
        }
        for (int i = 0; i <= n; i++)
            if (s - i >= 1 && !forb.contains(s - i) ||
                s + i <= n && !forb.contains(s + i)) {
                cout << i << "\n";
                break;
            }
    }
    return 0;
}
