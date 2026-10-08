#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0)
            S.insert((i - a % n + n) % n);
        else S.insert((a - i % n + n) % n);
    }
    cout << (S.size() == 1 ? "Yes" : "No") << "\n";
    return 0;
}
