#include <bits/stdc++.h>
using namespace std;

bool Solve(int x, const vector<int>& a, const vector<int>& b) {
    int res = 0;
    vector<int> seq;
    for (int i = 0; i < a.size(); i++)
        if (a[i] >= x && b[i] >= x)
            seq.push_back(1);
        else if (a[i] < x && b[i] < x)
            if (seq.empty() || seq.back() != -1)
                seq.push_back(-1);
    return accumulate(seq.begin(), seq.end(), 0) > 0;
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
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        int lef = 1, rig = 2 * n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Solve(mid, a, b))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
