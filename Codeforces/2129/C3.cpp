#include <bits/stdc++.h>
using namespace std;

vector<int> Construct(int lef, int rig, int x) {
    int n = 1;
    while (n * (n + 1) / 2 <= x)
        n++;
    n--;
    vector res = {lef};
    for (int i = 0; i < n - 1; i++) {
        res.push_back(lef);
        res.push_back(rig);
    }
    res.push_back(lef);
    int lft = x - n * (n + 1) / 2;
    for (int i = 0; i < lft; i++)
        res.push_back(lef);
    for (int i = 0; i < lft; i++)
        res.push_back(rig);
    res.push_back(rig);
    return res;
}

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
        constexpr int Maxd = 13;
        for (int i = 0; i < n; i += Maxd) {
            vector<int> toask;
            for (int j = 0; j < Maxd; j++) {
                int ind = (i + j) % n;
                ranges::copy(Construct(lef, ind, 1 << j), back_inserter(toask));
            }
            int val = Ask(toask);
            for (int j = 0; j < Maxd; j++) {
                int ind = (i + j) % n;
                if (val & 1 << j)
                    res[ind] = ')';
                else res[ind] = '(';
            }
        }
        cout << "! " << res << endl;
    }
    return 0;
}
