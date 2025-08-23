#include <bits/stdc++.h>
using namespace std;

int main() {
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
            if (a != -1)
                S.insert(a);
        }
        if (S.empty() || S.size() == 1 && *S.begin() > 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}