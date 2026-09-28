#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Check(const vector<int>& a) {
    map<int, vector<int>> M;
    for (int i = 0; i < a.size(); i++)
        M[a[i]].push_back(i);
    for (auto& V : M | views::values)
        if (V.size() != V.back() - V[0] + 1)
            return false;
    return true;
}

bool Solve(vector<int>& a) {
    map<int, vector<int>> M;
    for (int i = 0; i < a.size(); i++)
        M[a[i]].push_back(i);
    vector<ii> seq;
    for (auto& V : M | views::values) {
        int cnt = 0;
        for (int j = 0; j + 1 < V.size(); j++)
            if (V[j] + 1 < V[j + 1])
                cnt++;
        if (cnt >= 3)
            return false;
        if (cnt == 0)
            continue;
        if (V[0] > 0)
            seq.emplace_back(V[0] - 1, V.back());
        if (V.back() + 1 < a.size())
            seq.emplace_back(V.back() + 1, V[0]);
        for (int j = 0; j + 1 < V.size(); j++)
            if (V[j] + 1 < V[j + 1]) {
                seq.emplace_back(V[j] + 1, V.back());
                seq.emplace_back(V[j + 1] - 1, V[0]);
            }
        break;
    }
    if (seq.empty())
        return true;
    for (auto& [u, v] : seq) {
        swap(a[u], a[v]);
        if (Check(a))
            return true;
        swap(a[u], a[v]);
    }
    return false;
}

int main() {
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
        cout << (Solve(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}
