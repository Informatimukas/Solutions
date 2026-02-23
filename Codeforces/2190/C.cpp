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
        if (smaller) {
            if (Ask(i, D.front())) {
                D.push_front(i);
                continue;
            }
            int pnt = 1;
            while (pnt < D.size() && !Ask(i, D[pnt]))
                ++pnt;
            D.insert(D.begin() + pnt, i);
            smaller = false;
            continue;
        }
        if (Ask(D.back(), i)) {
            D.push_back(i);
            continue;
        }
        int pnt = 0;
        while (!Ask(i, D[pnt]))
            ++pnt;
        vector<int> res;
        for (int j = 1; j < i; j++)
            res.push_back(j);
        swap(i, D[pnt]);
        res.push_back(i);
        for (auto el : D)
            res.push_back(el);
        return res;
    }
    return {-1};
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
        auto res = Solve(n);
        cout << "!";
        for (auto el : res)
            cout << " " << el;
        cout << endl;
    }
    return 0;
}
