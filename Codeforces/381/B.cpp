#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> M;
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        M[a]++;
    }
    int nd = 1;
    deque<int> D;
    for (auto [key, value] : M | views::reverse) {
        int tk = min(nd, value);
        nd = 2;
        D.push_front(key);
        if (tk > 1)
            D.push_back(key);
    }
    cout << D.size() << "\n";
    for (int i = 0; i < D.size(); i++)
        cout << D[i] << (i + 1 < D.size() ? ' ' : '\n');
    return 0;
}
