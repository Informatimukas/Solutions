#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        set<int> S;
        int n;
        cin >> n;
        while (n--) {
            int a;
            cin >> a;
            S.insert(a);
        }
        while (!S.contains(S.size())) {
            int add = S.size();
            S.insert(S.size());
        }
        cout << S.size() << "\n";
    }
    return 0;
}
