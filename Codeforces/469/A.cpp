#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < 2; i++) {
        int p;
        cin >> p;
        while (p--) {
            int a;
            cin >> a;
            S.insert(a);
        }
    }
    cout << (S.size() == n ? "I become the guy." : "Oh, my keyboard!") << "\n";
    return 0;
}
