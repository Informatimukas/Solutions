#include <bits/stdc++.h>
using namespace std;

bool Solve(int a, int b, const vector<int>& bylvl, int to) {
    if (a > b)
        swap(a, b);
    for (int i = to; i >= 0; i--) {
        if (bylvl[i] <= a)
            a -= bylvl[i];
        else if (bylvl[i] <= b)
            b -= bylvl[i];
        else return false;
        if (a > b)
            swap(a, b);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector neigh(n + 1, vector<int>());
        vector<int> lvl(n + 1);
        vector bylvl(n + 1, 0);
        lvl[1] = 0;
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
            lvl[i] = lvl[p] + 1;
        }
        int mnlvl = n;
        for (int i = 1; i <= n; i++) {
            bylvl[lvl[i]]++;
            if (neigh[i].empty())
                mnlvl = min(mnlvl, lvl[i]);
        }
        int lef = 0, rig = mnlvl;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(k, n - k, bylvl, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
