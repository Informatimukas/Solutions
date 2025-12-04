#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> S;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }
    cout << 4 - S.size() << "\n";
    return 0;
}