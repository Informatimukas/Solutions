#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<ii> comeOrder;
    auto cmp = [](const ii& a, const ii& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    };
    set<ii, decltype(cmp)> bigOrder(cmp);
    int q;
    cin >> q;
    int id = 0;
    bool pr = false;
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int m;
            cin >> m;
            id++;
            comeOrder.insert({id, m});
            bigOrder.insert({id, m});
        } else {
            auto p = typ == 2? *comeOrder.begin(): *bigOrder.begin();
            comeOrder.erase(p);
            bigOrder.erase(p);
            if (pr) cout << " ";
            else pr = true;
            cout << p.first;
        }
    }
    cout << "\n";
    return 0;
}