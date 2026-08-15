#include <bits/stdc++.h>
using namespace std;

bool Solve(int n, priority_queue<int> Q) {
    while (!Q.empty() && n >= Q.size()) {
        n--;
        if (n >= 31)
            Q.pop();
        else {
            int v = Q.top() - (1 << n);
            Q.pop();
            if (v > 0)
                Q.push(v);
        }
    }
    return Q.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<int> Q;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            Q.push(a);
        }
        int lef = n, rig = n + 100;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Solve(mid, Q))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
