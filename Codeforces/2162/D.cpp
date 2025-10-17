#include <bits/stdc++.h>
using namespace std;

int Ask(int wh, int l, int r) {
    cout << wh << " " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

void Print(int l, int r) {
    cout << "! " << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int len = Ask(2, 1, n) - n * (n + 1) / 2;
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Ask(1, 1, mid) != Ask(2, 1, mid))
                rig = mid - 1;
            else lef = mid + 1;
        }
        Print(lef, lef + len - 1);
    }
    return 0;
}