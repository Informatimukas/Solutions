#include <bits/stdc++.h>
using namespace std;

int Ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

vector<int> Solve(int n) {
    deque D = {n};
    bool smaller = true;
    for (int i = n - 1; i > 0; i--) {
        if (smaller)
        if (smaller && Ask(i, D.front())) {
            D.push_front(i);
            continue;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        deque<int> D;
        D.push_back(n);

    }
    return 0;
}
