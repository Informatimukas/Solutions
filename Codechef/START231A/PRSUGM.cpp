#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& a, int mid) {
    if (a[0] < mid && a[1] < mid)
        return false;
    if (a[a.size() - 2] < mid && a.back() < mid)
        return false;
    int res = 0;

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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        if (n <= 2) {
            cout << *ranges::max_element(a) << "\n";
            continue;
        }
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(a, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
