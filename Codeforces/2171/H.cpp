#include <bits/stdc++.h>
using namespace std;

void Add(map<int, int>& M, int key, int val) {
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        --it;
        if (it->second >= val)
            return;
        if (it->first != key)
            ++it;
    }
    while (it != M.end() && val >= it->second)
        M.erase(it++);
    M.emplace(key, val);
}

int getBest(const map<int, int>& M, int key) {
    auto it = M.upper_bound(key);
    --it;
    return it->second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        map<int, int> M;
        Add(M, 0, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = (m - (n - i)) / i * i; j >= i; j -= i) {
                int cand = getBest(M, j - i);
                int num = j;
                while (num % i == 0) {
                    num /= i;
                    ++cand;
                }
                Add(M, j - i, cand);
            }
        }
        cout << M.rbegin()->second << "\n";
    }
    return 0;
}
