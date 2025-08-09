#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    while (n--) {
        int a;
        cin >> a;
        S.insert(a);
    }
    int nxt = 1;
    while (S.contains(nxt))
        nxt++;
    cout << nxt << "\n";
    return 0;
}