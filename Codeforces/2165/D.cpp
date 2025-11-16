#include <bits/stdc++.h>
using namespace std;

int joinLeftRight(const vector<int>& A, vector<int>& B) {
    int res = 0;
    int pnt = 0;
    for (auto& x : A)
        if (x != -1) {
            while (pnt < B.size() && (B[pnt] == -1 || B[pnt] <= x))
                pnt++;
            if (pnt >= B.size())
                break;
            res++;
            B[pnt] = -1;
        }
    return res;
}

int joinRightLeft(const vector<int>& B, vector<int>& A) {
    int res = 0;
    int pnt = static_cast<int>(A.size()) - 1;
    for (auto& x : B | views::reverse)
        if (x != -1) {
            while (pnt >= 0 && (A[pnt] == -1 || A[pnt] >= x))
                pnt--;
            if (pnt < 0)
                break;
            res++;
            A[pnt] = -1;
        }
    return res;
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
        vector lef(2 * n + 1, vector<int>());
        vector rig(2 * n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            lef[a].push_back(i);
            rig[a].push_back(i);
        }
        int res = n;
        for (int i = 1; i < 2 * n; i++) {
            res -= joinLeftRight(lef[i], rig[i + 1]);
            res -= joinRightLeft(rig[i], lef[i + 1]);
        }
        cout << res << "\n";
    }
    return 0;
}
