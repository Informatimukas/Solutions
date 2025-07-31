#include <bits/stdc++.h>
using namespace std;

int Ask(const vector<int>& seq) {
    cout << "? " << seq.size();
    for (auto &el: seq)
        cout << " " << el + 1;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int getInd(int L, int R) {
    int lef = L + 1, rig = R;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        vector<int> seq;
        for (int i = L; i <= mid; i++)
            seq.push_back(i);
        for (int i = L; i <= mid; i++)
            seq.push_back(i);
        if (Ask(seq) > 0)
            rig = mid - 1;
        else lef = mid + 1;
    }
    return lef > R? -1: lef;
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
        int lef = getInd(0, min(n - 1, 499));
        if (lef == -1) {
            lef = getInd(500, n - 1);
            if (lef == -1)
                lef = 500;
        }
        if (Ask({lef - 1, lef}) > 0)
            lef--;
        string res(n, '?');
        for (int i = 0; i < n; i += 2) {
            int ni = (i + 1) % n;
            int got = Ask({lef, lef, lef, i, ni, ni});
            res[i] = got % 2? ')': '(';
            res[ni] = got >= 2? ')': '(';
        }
        cout << "! " << res << endl;
    }
    return 0;
}
