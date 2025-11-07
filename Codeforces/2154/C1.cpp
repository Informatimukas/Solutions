#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

bool Contains(const set<int>& S, const vector<int>& divs) {
    return ranges::any_of(divs, [&S](auto&& x) { return S.contains(x); });
}

void Add(set<int>& S, const vector<int>& divs) {
    ranges::copy(divs, inserter(S, S.end()));
}

int Solve(const vector<int>& a, const vector<vector<int>>& divs) {
    set<int> S;
    for (auto& x : a) {
        if (Contains(S, divs[x]))
            return 0;
        Add(S, divs[x]);
    }
    for (auto& x : a)
        if (Contains(S, divs[x + 1]))
            return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector divs(Maxn, vector<int>());
    for (int i = 2; i < Maxn; i++)
        if (divs[i].empty())
            for (int j = i; j < Maxn; j += i)
                divs[j].push_back(i);
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
        cout << Solve(a, divs) << "\n";
    }
    return 0;
}