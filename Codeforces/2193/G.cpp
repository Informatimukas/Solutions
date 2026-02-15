#include <bits/stdc++.h>
using namespace std;

int Ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

optional<int> Traverse(const vector<vector<int>>& neigh, int v, int p, bool& solved) {
    optional cur = {v};
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        auto got = Traverse(neigh, u, v, solved);
        if (cur && got) {
            if (!solved) {
                int ask = Ask(*cur, *got);
                if (ask) {
                    int pr = Ask(*cur, *cur) ? *cur : *got;
                    cout << "! " << pr << endl;
                    solved = true;
                }
            }
            cur = {};
        } else if (!cur)
            cur = got;
    }
    return cur;
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
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        bool solved = false;
        auto root = Traverse(neigh, 1, 0, solved);
        if (!solved)
            cout << "! " << *root << endl;
    }
    return 0;
}
