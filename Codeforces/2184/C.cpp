#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int Get(const map<int, int, greater<int>>& M, int x) {
    auto it = M.find(x);
    return it == M.end() ? Inf : it->second;
}

void Add(map<int, int, greater<int>>& M, int key, int val) {
    if (Get(M, key) > val)
        M[key] = val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int, greater<int>> M;
        M.insert({n, 0});
        int res = -1;
        for (auto it = M.begin(); it != M.end(); ++it) {
            if (it->first == k) {
                res = it->second;
                break;
            }
            Add(M, it->first / 2, it->second + 1);
            Add(M, (it->first + 1) / 2, it->second + 1);
        }
        cout << res << "\n";
    }
    return 0;
}