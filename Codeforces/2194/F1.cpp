#include <bits/stdc++.h>
using namespace std;

struct node {
    int a;
    vector<int> neigh;
};

int getGood(const vector<int>& )

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        vector<int> good(k);
        for (auto& x : good)
            cin >> x;

    }
    return 0;
}
