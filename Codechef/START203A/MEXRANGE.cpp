#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> res;
        deque<int> cur;
        for (int i = n - 1; i >= 0; i--)
            if (s[i + 1] == '1') {
                res.insert(res.end(), cur.begin(), cur.end());
                cur = {i};
            } else if (!cur.empty())
                cur.push_front(i);
        res.push_back(cur.back());
        while (res.size() < n)
            res.push_back(n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}