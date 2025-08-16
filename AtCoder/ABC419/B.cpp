#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<>> Q;
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x; cin >> x;
            Q.push(x);
        } else {
            cout << Q.top() << "\n";
            Q.pop();
        }
    }
    return 0;
}