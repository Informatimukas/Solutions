#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> seq;
    vector<int> un;
    while (n--) {
        int k, x1, x2;
        cin >> k >> x1 >> x2;
        int rig = x2;
        vector<int> a(k);
        for (auto& x : a) {
            cin >> x;
            rig -= x;
        }
        int lef = x1;
        seq.push_back({0, lef, 0});
        for (auto x : a) {
            seq.push_back({lef, lef + x, rig});
            lef += x;
            rig -= x;
        }
        seq.push_back({lef, rig, })
    }
    return 0;
}