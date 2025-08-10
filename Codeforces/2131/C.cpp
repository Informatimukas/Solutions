#include <bits/stdc++.h>
using namespace std;

int Get(int a, int k) {
    a %= k;
    return min(a, k - a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        multiset<int> S, T;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(Get(a, k));
        }
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            T.insert(Get(b, k));
        }
        cout << (S == T ? "YES": "NO") << "\n";
    }
    return 0;
}
