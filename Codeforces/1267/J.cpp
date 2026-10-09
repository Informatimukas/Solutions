#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Add(map<int, int>& M, int key, int val) {
    if (M.contains(key))
        M[key] = min(M[key], val);
    else M.insert({key, val});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> M;
        vector<ii> res(n + 5);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            M[c]++;
        }
        for (auto v : M | views::values) {
            map<int, int> my;
            for (int i = 1; i <= v; i++) {
                int got = v / i;
                Add(my, got + 1, i);
                if (v % i == 0)
                    Add(my, got, i);
            }
            for (auto& [key, val] : my) {
                res[key].first++;
                res[key].second += val;
            }
        }
        for (int i = res.size() - 1; i > 0; i--)
            if (res[i].first == M.size()) {
                cout << res[i].second << "\n";
                break;
            }
    }
    return 0;
}
